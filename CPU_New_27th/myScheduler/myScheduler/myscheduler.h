#include "mycpu.h"
using namespace std;

void myProcess :: schedule(char algorithm, int timeslice)
{
	PCB *cur_process, *IO_header, *ready_process;
	int i, IO_count, string_length;
	if (runningQ.is_queue_empty() == SUCCESS)				// No process executing currently
	{
		total_ticks = 0;
		/* If using STCF, then sort readyQ before pick the highest */
		/* priority process in the ready Q to run */
		if ((algorithm == 'S') || (algorithm == 'N'))
			priority_sort(readyQ);
		dispatch(); /* If no process running, run the next one */
	}
	else													// Some process is already running
	{
		runningQ.retrieve(cur_process);
		if (cur_process->timeleft == 0)						// Remove the process if it has completed its execution
		{
			runningQ.remove(cur_process); /* Process is done executing */
			cout << "Process " << cur_process->process_id << " completed execution.";
			cout << " Removing it from the system." << endl;
			longTermScheduler(poolQ, readyQ);
			/* Print out process cycle graph */
			string_length = strlen(cur_process->process_graph);
			cout << cur_process->process_graph << endl;
			/* Print out to file process cycle graph */
			fprint_cycle(cur_process);
			/* Update the timing global variables with this process' values */
			total_cpu_time += cur_process->cpu_time;
			total_IOwait_time += cur_process->IOwait_time;
			total_wait_time += cur_process->wait_time;
			/* Run the next available process in the ready Q */
			/* and reset total_ticks global var for RR */
			total_ticks = 0;
			/* If using STCF, then sort readyQ before pick the highest */
			/* priority process in the ready Q to run */
			if ((algorithm == 'S') || (algorithm == 'N'))
				priority_sort(readyQ);
			dispatch();
		}
		else /* Process is not done executing */
		{
			/* Send it to DeviceQ if it is asking for IO */
			if ((cur_process->num_of_IO > 0) && (cur_process->IO[cur_process->current_IO] == 0)
					&& (cur_process->num_of_IO != cur_process->current_IO))
			{
				/*  Send the process to DeviceQ for IO and run the next available process from the readyQ */
				cout << "Sending process " << cur_process->process_id << " to DeviceQ." << endl;
				suspend();
				total_ticks = 0;
				/* If using STCF, then sort readyQ before pick the highest */
				/* priority process in the ready Q to run */
				if ((algorithm == 'S') || (algorithm == 'N'))
					priority_sort(readyQ);
				dispatch();
			} /* end of if statement (process IO check) */
			else if ((algorithm == 'R') && (total_ticks % timeslice == 0) && (total_ticks > 0))
			{
				cout << "----- TIME SLICE UP!! PREEMPT!! -----" << endl;
				total_ticks = 0; /* Reset global var */
				dispatch(); /* Time slice is up, so process switch! */
			} /* end of else if (RR time slice check) */
			else if (algorithm == 'S')
			{
				/* Only STCF with preemption gets to preempt a runnning process */
				/* if its priority is lower than the highest priority ready process */
				if(readyQ.is_queue_empty() == FAILURE)
				{
					priority_sort(readyQ);
					readyQ.retrieve(ready_process);
					if (ready_process->priority < cur_process->priority)
					{
						cout << "Higher Priority process ready for execution" << endl;
						cout << "Running process " << cur_process->process_id <<  " priority : " << cur_process->priority << endl;
						cout << "Ready process " << ready_process->process_id << " priority : " << ready_process->priority << endl;
						dispatch();
					}
				}
			} /* end of else if statement (Check for STCF) */
		} /* end of if statement (process done check) */
	} /* end of if statement (empty running Q check) */
	if (deviceQ.is_queue_empty() == FAILURE)
	{
		IO_count = deviceQ.getnumcount();
		/* Check all IO processes to see if they completed their I/O */
		for (i = 0; i < IO_count; i++)
		{
			deviceQ.remove(IO_header);
			if ((IO_header->IO[IO_header->current_IO] == 0)
				&& (IO_header->IO_lengths[IO_header->current_IO]
				== 0))
			{
				/* process completed I/O, so resume its execution */
				cout << "Process " << IO_header->process_id << " completed its current IO. Sending it to readyQ." << endl;
				resume(IO_header);
			}
			else
				deviceQ.insert(IO_header);
		} /* end of for loop (went through IO Q) */
	} /* end of if statement (resumption checks) */
//	cout << "Leaving SCHEDULER...." << endl;
} /* end of scheduler */

void myProcess::time_tick()
{
	cout << "-------------- Time Tick!!! --------------" << endl;
	PCB *current_process, *IO_header;
	int i, IO_count;

	/* Decrement computation time and time to IO if any for running processes */

	if (runningQ.is_queue_empty() == FAILURE)
	{
		runningQ.retrieve(current_process);
		if (current_process->timeleft > 0)
			current_process->timeleft--;
		for (i = 0; i < current_process->num_of_IO; i++)
		{
			if (current_process->IO[i] > 0)
				current_process->IO[i]--;
		}
		cout << "Running process " << current_process->process_id << endl;
			print_process_info(current_process);
	}

	/* Decrement IO lengths for all IO processes */
	if (deviceQ.is_queue_empty() == FAILURE)
	{
		IO_count = deviceQ.getnumcount();
		for (i = 0; i < IO_count; i++)
		{
			deviceQ.remove(IO_header);
			if (IO_header->IO_lengths[IO_header->current_IO] > 0)
				IO_header->IO_lengths[IO_header->current_IO]--;
			deviceQ.insert(IO_header);
		}
	}

	if ((readyQ.is_queue_empty() == SUCCESS) && (runningQ.is_queue_empty() == SUCCESS) && (deviceQ.is_queue_empty() == FAILURE))
	{
		cout << "CPU Time Idle" << endl;
		total_idle_time++;
	}
	
	cout << "In readyQ" << endl;
	readyQ.print();
	cout << "In runningQ" << endl;
	runningQ.print();
	cout << "In deviceQ" << endl;
	deviceQ.print();

	/* Update the process cycle graphs for all processes in the system */
	update_graphs();

	/* Update the process' priorities */
	update_priorities();

	/* Increment total_ticks because a time tick occurred */
	total_ticks++;
}
#pragma once

#include <fstream>
#include <stdlib.h> 									// atoi()
#include <ctype.h> 										// isdigit()
#include <string> 										// strcat(), strlen()
#include <Windows.h>
#include "myqueue.h"
#include "ProcessGenerator.h"

using namespace std;

int algorithm;
#define MAXALGORITHMS 5
#define myFCFS 0;
#define myRR3 1;
#define myRR6 2;
#define mySTCF 3;
#define mySTCFP 4;

int longtermCounter;
int firstTime = 1;

#define SLEEP_VAL 0										// Degree of output slow:fast
#define MAXBLOCKS 20
#define MAXBLOCK_LENGTH 20
#define BUFFER_LENGTH 5
#define MAXPROCESS 200
#define YES 1
#define NO 0

enum state { Running, Ready, Waiting };

struct myReadings
{
	double cpuUtil[MAXALGORITHMS];
	double avgReadyWaitTime[MAXALGORITHMS];
	double avgIOWaitTime[MAXALGORITHMS];
	double throughput[MAXALGORITHMS];
	double avgTurnAroundTime[MAXALGORITHMS];
};
myReadings *m1 = new myReadings;					// Global pointer to myReadings for Algorithm Comparison
myReadings m2;					// Global Pointer to myReadings for IO Analysis
int io_analysis_counter = 0;
/* Process Control Block */
struct PCB
{
	int process_id;
	int priority;
	char process_graph[10000];
	int timeleft;
	int IOwait_time;
	int cpu_time;
	int wait_time;
	int num_of_IO;
	int current_IO;
	int IO[MAXBLOCKS];
	int IO_lengths[MAXBLOCK_LENGTH];
	int inPool;
	state status;
};

/* Function prototypes */
class myProcess
{
public:
	myProcess();

	void schedule(char, int);
	void dispatch();
	void suspend();
	void resume(PCB *);

	void FCFS();
	void RR(int timeslice, process_list *list_head);
	void STCF(int preemption, process_list *list_head);

	void print_process_info(PCB *);
	void fprint_cycle(PCB *);
	void update_graphs();
	void update_priorities();
	void print_results();
	int get_input(char buffer[BUFFER_LENGTH]);

	void time_tick();

	/*Queue Operations*/
	typedef queue<PCB> qType;
	void longTermScheduler(qType& sourceQ, qType& destinationQ);
	void getLongTermCount(qType& sourceQ);
	void fill_poolQ_from_file();
	void fill_poolQ_direct(process_list *list_head);
	void get_tasks(qType&, qType&);
	void priority_sort(qType&);

private:
	int total_idle_time;
	int total_cpu_time;
	int total_IOwait_time;
	int total_wait_time;
	int total_ticks;
	qType poolQ, readyQ, runningQ, deviceQ;
};

myProcess :: myProcess()
{
	total_idle_time = 0;
	total_cpu_time = 0;
	total_IOwait_time = 0;
	total_wait_time = 0;
	total_ticks = 0;										// Used in keeping track of time slices in RR
}


void myProcess :: suspend()
{
	PCB *current_process;
	/* Block a running process for I/O event and put it in IO Q*/
	runningQ.remove(current_process);
	deviceQ.insert(current_process);
	current_process->status = Waiting;
}

void myProcess :: resume(PCB *IO_process)
{
	/* Resume a IO process (I/O complete) by making it ready */
	/* If the runningQ is empty then just run the process */
	if (runningQ.is_queue_empty() == SUCCESS)
	{
		runningQ.insert(IO_process);
		IO_process->status = Running;
	}
	else
	{
		readyQ.insert(IO_process);
		IO_process->status = Ready;
	}
	IO_process->current_IO++;
}

void myProcess :: fill_poolQ_from_file()
{
	FILE *fp;
	char buffer[BUFFER_LENGTH];
	int input, queue_count, i;
	PCB *pcb;

	/* Open cpu.dat for reading */
	fp = fopen("cpu.dat", "r");
	if ( fp == NULL )
	{
		cout << "Cannot find cpu.dat!" << endl;
		return;
	}

	/* If a poolQ already exists then make it empty */
	if (poolQ.is_queue_empty() == FAILURE)
	{
		queue_count = poolQ.getnumcount();
		for(i=0; i < queue_count; i++)
			poolQ.remove(pcb);
	}

	/* Fill the poolQ with processes from cpu.dat */
	while (fgets(buffer, sizeof(buffer), fp))
	{
		input = get_input(buffer);									// Convert to Integer
		switch (buffer[0])
		{
			case 'p':												// Create a new PCB and Initialize other fields
				pcb = new PCB;
				cout << buffer[0];
				cout << buffer[1] << endl;
				pcb->process_id = input;
				pcb->status = Ready; 								// Processes enter as Ready
				pcb->num_of_IO = 0;
				pcb->current_IO = 0;
				pcb->IOwait_time = 0;
				pcb->cpu_time = 0;
				pcb->wait_time = 0;
				for(i=0; i < 255; i++)
					pcb->process_graph[i] = '\0';
				break;
			case 'a':												// Priority
				pcb->priority = get_input(buffer);
				break;
			case 't':												// How many Time Ticks it will run for?
				pcb->timeleft = get_input(buffer);
				break;
			case 'b':												// When does the process block for IO?
				pcb->IO[pcb->num_of_IO] = get_input(buffer);
				break;
			case 'c':												// How long is the IO (in Time Ticks)?
				pcb->IO_lengths[pcb->num_of_IO] = get_input(buffer);
				pcb->num_of_IO ++;
				break;
			case 'e':												// Insert process into poolQ
				cout << "Inserting process " << pcb->process_id << " to PoolQ" << endl;
				poolQ.insert(pcb);
				break;
		}
	}
	fclose(fp);
}

void myProcess :: get_tasks(qType& sourceQ, qType& destinationQ)
{
	/*Copies process from one queue to another */
	PCB *pcb;
	int count,i;
	count = sourceQ.getnumcount();
	for(i=count ; i>0; i--)
	{
		sourceQ.remove(pcb);
		destinationQ.insert(pcb);
		sourceQ.insert(pcb);
	}
}

void myProcess :: priority_sort(qType& queue)
{
//	cout << "Sorting processes according to their priority." << endl;
	PCB* pcb[MAXPROCESS];
	PCB *temp_process;
	int num_processes, i, j;
	/* Dequeue all PCBs on the queue */
	num_processes = queue.getnumcount();
	for(i=0; i < num_processes; i++)
		queue.remove(pcb[i]);
	/* Swap PCB's in the array if they are misplaced */
	for(i=0; i < num_processes; i++)
	{
		for(j=i+1; j < num_processes; j++)
		{
			if(pcb[i]->priority > pcb[j]->priority)
			{
				temp_process = pcb[i];
				pcb[i] = pcb[j];
				pcb[j] = temp_process;
			} /* end of if statement */
		} /* end of j for loop */
	} /* end of i for loop */
	/* Enqueue all PCBs back on the queue sorted by priority */
	for(i=0; i < num_processes; i++)
		queue.insert(pcb[i]);
} /* end of priority_sort(qType&) */

int myProcess :: get_input(char buffer[BUFFER_LENGTH])
{
	const int base = 10;
	const char newline = '\n';
	int integer_value = 0, i = 0, digit;
	/* Get the integer value of the passed-in buffer */
	while (buffer[i] != newline)
	{
		if ( isdigit(buffer[i]) )
		{
			digit = int (buffer[i]) - int ('0');
			integer_value = base * integer_value + digit;
		}
		i++;
	} /* end of while loop */
	return integer_value;
} /* end of get_input(char[]) */

void myProcess :: print_process_info(PCB *process)
{
	int IOs = process->num_of_IO, i;
	cout << "Its computation time left is " << process->timeleft << endl;
	if (IOs == 0)
		cout << "Does not have IO" << endl;
	else
	{
		for (i=0; i < IOs; i++)
		{
	//		cout << "It has an IO at " << process->IO[i] << " for " <<
	//		process->IO_lengths[i] << " time units" << endl;
		} /* end of for loop (goes through number of IOs) */
	} /* end of if statement */
} /* end of print_process_info(PCB*) */

void myProcess :: update_graphs()
{
	PCB *running_process = NULL, *IO_process = NULL, *ready_process = NULL, *pool_process = NULL;
	const char *running = "-", *IO = "|", *ready = "/", *pool = "+";
	int i, queue_count;
	/* Used to update the stats (cpu, waiting and ready) times */
	/* for all processes in the system */
	if (runningQ.is_queue_empty() == FAILURE)
	{
		runningQ.remove(running_process);
		// cout << "Before concatRu: " << running_process->process_graph << endl;
		strcat(running_process->process_graph, running);
		// cout << "After concatRu: " << running_process->process_graph << endl;
		running_process->cpu_time++;
		runningQ.insert(running_process);
	} /* end of if statement */
	if (deviceQ.is_queue_empty() == FAILURE)
	{
		queue_count = deviceQ.getnumcount();
		for(i=0; i < queue_count; i++)
		{
			deviceQ.remove(IO_process);
			// cout << "Before concatW: " << IO_process->process_graph << endl;
			strcat(IO_process->process_graph, IO);
			// cout << "After concatW: " << IO_process->process_graph << endl;
			IO_process->IOwait_time++;
			deviceQ.insert(IO_process);
		} /* end of for loop */
	} /* end of if statement */
	if (readyQ.is_queue_empty() == FAILURE)
	{
		queue_count = readyQ.getnumcount();
		for(i=0; i < queue_count; i++)
		{
			readyQ.remove(ready_process);
			// cout << "Before concatRe: " << ready_process->process_graph << endl;
			strcat(ready_process->process_graph, ready);
			// cout << "After concatRe: " << ready_process->process_graph << endl;
			ready_process->wait_time++;
			readyQ.insert(ready_process);
		} /* end of for loop */
	} /* end of if statement */
	//--------------------------------------
	if (poolQ.is_queue_empty() == FAILURE)
	{
		queue_count = poolQ.getnumcount();
		for (i = 0; i < queue_count; i++)
		{
			poolQ.remove(pool_process);
			// cout << "Before concatRe: " << ready_process->process_graph << endl;
			if (pool_process->inPool == 1)
			{
				strcat(pool_process->process_graph, pool);
			}
			// cout << "After concatRe: " << ready_process->process_graph << endl;
		//	pool_process->wait_time++;
			poolQ.insert(pool_process);
		} /* end of for loop */
	} /* end of if statement */
} /* End of update_graphs() */

void myProcess :: update_priorities()
{
	PCB *process = NULL;
	int i, j, queue_count, temp_time;
	int time_buf[MAXPROCESS];
	/* Initialize time buffer to all -1 */
	for(i=0; i < MAXPROCESS; i++)
		time_buf[i] = -1;
	if (poolQ.is_queue_empty() == FAILURE)
	{
		queue_count = poolQ.getnumcount();
		for(i=0; i < queue_count; i++)
		{
			/* Fill up time buffer with actual timeleft values */
			/* of all processes in the system */
			poolQ.remove(process);
			time_buf[i] = process->timeleft;
			poolQ.insert(process);
		} /* end of for loop */
	} /* end of if statemnt */
	/* Sort time buffer according to increasing timeleft values */
	for(i=0; i < queue_count; i++)
	{
		for(j=i+1; j < queue_count; j++)
		{
			if (time_buf[i] > time_buf[j])
			{
				temp_time = time_buf[i];
				time_buf[i] = time_buf[j];
				time_buf[j] = temp_time;
			} /* end of if statement (swapping condition) */
		} /* end of j for loop */
	} /* end of i for loop */
	/* Update the priority field of each process according to */
	/* the sorted time buffer */
	for(i=0; i < queue_count; i++)
	{
		poolQ.remove(process);
		for(j=0; j < queue_count; j++)
		{
			if (process->timeleft == time_buf[j])
			{
				// cout << "For process " << process->process_id << endl;
				// cout << "Old priority is: " << process->priority << endl;
				// cout << "New priority is: " << j+1 << endl;
				process->priority = j+1;
			} /* end of if statement */
		} /* end of j for loop (goes through time buffer) */
		poolQ.insert(process);
	} /* end of i for loop (goes through processes) */
} /* End of update_priorities() */

void myProcess :: print_results()
{
	int num_of_processes, total_turn_time, total_time, i;
	unsigned int starting_time;
	float avg_IOwait_time, avg_wait_time, avg_turn_time, throughput, cpu_util;
	PCB *removed_process;
	num_of_processes = poolQ.getnumcount();
	poolQ.remove(removed_process);
	starting_time = strlen(removed_process->process_graph);
	poolQ.insert(removed_process);
	/* Find out longest process cycle graph */
	for(i=0; i < num_of_processes; i++)
	{
		poolQ.remove(removed_process);
		if (starting_time < strlen(removed_process->process_graph) )
			starting_time = strlen(removed_process->process_graph);
		poolQ.insert(removed_process);
	}
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Maximum Cycles: " << starting_time << endl;
	cout << "Total Idle Time: " << total_idle_time << endl;
	cout << "Total CPU Time is:\t\t" << total_cpu_time << endl;
	cout << "Total Wait Time is:\t\t" << total_wait_time << endl;
	cout << "Total IOWait Time is:\t\t" << total_IOwait_time << endl;
	cout << "Number of processes:\t\t" << num_of_processes << endl;
	cout << "Total Time is:\t\t\t" << starting_time << endl;
	/* Statistical calculations */
	//total_time = starting_time;
	total_time = total_cpu_time + total_idle_time;
	throughput = (float)num_of_processes / total_time;
	avg_IOwait_time = (float)total_IOwait_time / num_of_processes;
	avg_wait_time = (float)total_wait_time / num_of_processes;
	total_turn_time = total_IOwait_time + total_cpu_time + total_wait_time;
	avg_turn_time = (float)total_turn_time / num_of_processes;
	cpu_util = (float)total_cpu_time / total_time;
	cpu_util *= 100;
	cout << "Throughput Is:\t\t\t" << throughput << endl;
	cout << "Average Wait Time Is:\t\t" << avg_wait_time << endl;
	cout << "Average IOwait Time Is:\t\t" << avg_IOwait_time << endl;
	cout << "Average Turnaround Time Is:\t" << avg_turn_time << endl;
	cout << "CPU Utilization Is:\t\t" << cpu_util << " percent" << endl;

	// -----------------------------------------------------------//
	// Make entry in myReading Structure for Displaying Graphs
	m1->throughput[algorithm] = throughput;
	m1->avgIOWaitTime[algorithm] = avg_IOwait_time;
	m1->avgReadyWaitTime[algorithm] = avg_wait_time;
	m1->cpuUtil[algorithm] = cpu_util;
	m1->avgTurnAroundTime[algorithm] = avg_turn_time;
	// -----------------------------------------------------------//

	// -----------------------------------------------------------//
	// Make entry in myReading Structure for Displaying Graphs
	m2.throughput[0] = throughput;
	m2.avgIOWaitTime[0] = avg_IOwait_time;
	m2.avgReadyWaitTime[0] = avg_wait_time;
	m2.cpuUtil[0] = cpu_util;
	m2.avgTurnAroundTime[0] = avg_turn_time;
	io_analysis_counter++;
	// -----------------------------------------------------------//
	
	ofstream fout("results.txt",ios::app);
	if (!fout)
		cout << "Cannot open results.txt for writing!" << endl;
	fout << endl;
	fout << "Maximum Cycles:\t\t" << starting_time << endl;
	fout << "Total Idle Time:\t\t" << total_idle_time << endl;
	fout << "Total CPU Time is:\t\t" << total_cpu_time << endl;
	fout << "Total Wait Time is:\t\t" << total_wait_time << endl;
	fout << "Total IOWait Time is:\t" << total_IOwait_time << endl;
	fout << "Number of processes:\t" << num_of_processes << endl;
	fout << "Total time is:\t\t" << total_time << endl;
	fout << "Throughput Is:\t\t" << throughput << endl;
	fout << "Average Wait Time is:\t" << avg_wait_time << endl;
	fout << "Average IOwait Time is:\t" << avg_IOwait_time << endl;
	fout << "Average Turnaround Time is:\t" << avg_turn_time << endl;
	fout << "CPU Utilization is:\t\t" << cpu_util << endl;
	fout.close();
	/* Reset global variables to initial values */
	total_IOwait_time = total_cpu_time = total_wait_time = total_ticks = 0;
} /* End of print_results() */

void myProcess :: fprint_cycle(PCB *process)
{
	/* Open results.txt for appending */
	ofstream fout("results.txt",ios::app);
	if (!fout)
		cout << "Cannot open results.txt for writing!" << endl;
	/* Print out to file process cycle graph */
	fout << "Process cycle graph for process " << process->process_id << endl;
	fout << process->process_graph << endl;
	fout.close();
} /* End of fprint_cycle(PCB*) */

void myProcess::fill_poolQ_direct(process_list *list_head)
{
	int counter = 0, queue_count, i;
	
	PCB *pcb;

	/* If a poolQ already exists then make it empty */
	if (poolQ.is_queue_empty() == FAILURE)
	{
		queue_count = poolQ.getnumcount();
		for (i = 0; i < queue_count; i++)
			poolQ.remove(pcb);
	}

	while (list_head != NULL)											// Copy the Linkedlist to the poolQ
	{
		// Create a new PCB and Initialize other fields
		pcb = new PCB;
		pcb->status = Ready; 											// Processes enter as Ready
		pcb->current_IO = 0;
		pcb->IOwait_time = 0;
		pcb->cpu_time = 0;
		pcb->wait_time = 0;
		pcb->inPool = 1;
		for (i = 0; i < 10000; i++)
			pcb->process_graph[i] = '\0';

		pcb->process_id = list_head->process->pid;
		pcb->priority = list_head->process->priority;
		pcb->timeleft = list_head->process->burst_length;				// How many Time Ticks it will run for?
		pcb->num_of_IO = list_head->process->numberofIOs;
		for (int i = 0; i < pcb->num_of_IO; i++)
		{
			pcb->IO[i] = list_head->process->block_time[i];				// When does the process block for IO?
			pcb->IO_lengths[i] = list_head->process->block_length[i];	// How long is the IO (in Time Ticks)?
		}
				
		// Insert process into poolQ
		cout << "Inserting process " << pcb->process_id << " to PoolQ" << endl;
		poolQ.insert(pcb);
		
		counter++;
		list_head = list_head->next;
	}
	
	cout << "\nTotal " << counter << " processes inserted successfully...!!!" << endl;
}
void myProcess::longTermScheduler(qType& sourceQ, qType& destinationQ)
{
	/*Copies process from one queue to another */
	PCB *pcb;
	int i, dest_count, diff;

//	dest_count = destinationQ.getnumcount();
	//diff = 5 - dest_count;

	if (firstTime)
	{
		firstTime = 0;
		int i = 1;
		while (longtermCounter > 0 && i < 6)
		{
			int pid1;
			//		dest_count++;
			sourceQ.remove(pcb);
			pid1 = pcb->process_id;
			pcb->inPool = 0;
			destinationQ.insert(pcb);
			sourceQ.insert(pcb);
			longtermCounter--;
			cout << "\nDestination Count : " << dest_count << endl;
			cout << "Process " << pid1 << " added to ready queue" << endl;
			cout << "counter value: " << longtermCounter << endl;
			i++;
		}
	}
	else if(longtermCounter > 0)
	{
		int pid1;
//		dest_count++;
		sourceQ.remove(pcb);
		pid1 = pcb->process_id;
		pcb->inPool = 0;
		destinationQ.insert(pcb);
		sourceQ.insert(pcb);
		longtermCounter--;
		cout << "\nDestination Count : " << dest_count << endl;
		cout << "Process " << pid1 << " added to ready queue" << endl;
		cout << "counter value: " << longtermCounter << endl;
	}
}

void myProcess::getLongTermCount(qType& sourceQ)
{
	longtermCounter = sourceQ.getnumcount();
}
#include "mycpu.h"

void myProcess::dispatch()
{
	PCB *to_be_run_process, *preempted_process;
	/* Preempt running process if any and move it to readyQ */
	if (runningQ.is_queue_empty() == FAILURE)
	{
		runningQ.remove(preempted_process);
		cout << "Preempted process " << preempted_process->process_id << " from the runningQ" << endl;
		print_process_info(preempted_process);
		readyQ.insert(preempted_process);
		preempted_process->status = Ready;
	}
	/* Make a ready process running */
	if (readyQ.is_queue_empty() == FAILURE)
	{
		readyQ.remove(to_be_run_process);
		cout << "Dispatching process " << to_be_run_process->process_id << " from the readyQ" << endl;
		print_process_info(to_be_run_process);
		runningQ.insert(to_be_run_process);
		to_be_run_process->status = Running;
	}
	else
	{
		//		cout << "Nothing to Schedule in the Ready Queue." << endl;
	}
} /* end of dispatch() */
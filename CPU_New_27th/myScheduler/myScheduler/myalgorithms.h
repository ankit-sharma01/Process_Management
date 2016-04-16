#include "mycpu.h"
#include "myscheduler.h"
#include "mydispatcher.h"

using namespace std;
extern int algorithm;

void myProcess :: FCFS()
{
	total_idle_time = 0;
	algorithm = myFCFS;
	cout << "In FCFS()..." << endl;
	/* Retrieve the tasks from the pool Q into the ready Q */
//	get_tasks(poolQ, readyQ);
	getLongTermCount(poolQ);
	longTermScheduler(poolQ, readyQ);
	cout << "Processes inserted into ReadyQ from the Pool" << endl;

	/* While at least one queue is not empty, schedule the task set */
	while ( (readyQ.is_queue_empty() == FAILURE) || (deviceQ.is_queue_empty() == FAILURE) || (runningQ.is_queue_empty() == FAILURE) )
	{
		/* Call the scheduler for FCFS scheduling (0 timeslice) */
		schedule('F',0);

		/* Call the time_tick which will update PCB timings */
		time_tick();
		/* Simulate a time tick (currently 2 sec) */
//		Sleep(SLEEP_VAL);
	} /* end of while loop */
	/* Output statistics of algorithm to screen */
	print_results();
	cout << "Leaving FCFS()..." << endl;
} /* end of FCFS() */

void myProcess::RR(int timeslice, process_list *list_head)
{

	total_idle_time = 0;
	if (timeslice == 3)
	{
		algorithm = myRR3;
	}
	else
	{
		algorithm = myRR6;
	}

	cout << "In RR(int)..." << "with a time slice of " << timeslice << endl;
	/* Drain poolQ and re-queue input task set into it */
	//	p1.fill_poolQ_from_file();
	fill_poolQ_direct(list_head);
	/* Retrieve the tasks from the pool Q into the ready Q */
	//	get_tasks(poolQ, readyQ);
	getLongTermCount(poolQ);
	longTermScheduler(poolQ, readyQ);
	/* While at least one queue is not empty, schedule the task set */
	while ( (readyQ.is_queue_empty() == FAILURE) || (deviceQ.is_queue_empty() == FAILURE) || (runningQ.is_queue_empty() == FAILURE) )
	{
		/* Call the scheduler for RR scheduling (with timeslice) */
		schedule('R',timeslice);

		/* Call the time_tick which will update PCB timings */
		time_tick();
		/* Simulate a time tick (currently 2 sec) */
//		Sleep(SLEEP_VAL);
	} /* end of while loop */
	/* Output statistics of algorithm to screen */
	print_results();
	cout << "Leaving RR(" << timeslice << ")..." << endl;
} /* end of RR(int) */

void myProcess::STCF(int preemption, process_list *list_head)
{
	total_idle_time = 0;
	if (preemption == 0)
	{
		algorithm = mySTCF;
	}
	else
	{
		algorithm = mySTCFP;
	}
	cout << "In STCF()..." << endl;
	/* Drain poolQ and re-queue input task set into it */
	//	p1.fill_poolQ_from_file();
	fill_poolQ_direct(list_head);
	/* Retrieve the tasks from the pool Q into the ready Q */
	//	get_tasks(poolQ, readyQ);
	getLongTermCount(poolQ);
	longTermScheduler(poolQ, readyQ);
	/* While at least one queue is not empty, schedule the task set */
	while ( (readyQ.is_queue_empty() == FAILURE) || (deviceQ.is_queue_empty() == FAILURE) || (runningQ.is_queue_empty() == FAILURE) )
	{
		/* Call the scheduler for STCF scheduling */
		if (preemption == YES)
			schedule('S',0);
		else if (preemption == NO)
			schedule('N',0);
		/* cast to appropriate type */
		/* Call the time_tick which will update PCB timings */
		time_tick();
		/* Simulate a time tick (currently 2 sec) */
//		Sleep(SLEEP_VAL);
	} /* end of while loop */
	/* Output statistics of algorithm to screen */
	print_results();
	cout << "Leaving STCF" << endl;
} /* end of STCF() */

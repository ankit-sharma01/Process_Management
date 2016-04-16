#include <fstream>
#include "mycpu.h"
#include "myalgorithms.h"

int run_algorithms(int algorithm, process_list *&list_head)
{
	myProcess p1;
	/* Fill the poolQ with the task set */
//	p1.fill_poolQ_from_file();
	p1.fill_poolQ_direct(list_head);	
	
	/* Clear out results.txt */
	ofstream fout("results.txt");
	if (!fout)
		cout << "Cannot open results.txt for truncation!" << endl;
	fout.close();

	ofstream foutapp("results.txt",ios::app);
	if (!foutapp)
		cout << "Cannot open results.txt for appending!" << endl;

	switch (algorithm)
	{
		case 1:
				cout << "------------------------ Testing FCFS ------------------------" << endl;
				foutapp << "Testing FCFS..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.FCFS();
				break;
		case 2:
				cout << "------------------------ Testing RR with Time Slice : 3 ------------------------" << endl;
				foutapp << "Testing RR(3)..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.RR(3, list_head);
				break;
		case 3:
				cout << "------------------------ Testing RR with Time Slice : 6 ------------------------" << endl;
				foutapp << "Testing RR(6)..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.RR(6, list_head);
				break;
		case 4:
				cout << "------------------------ Testing STCF() without preemption ------------------------" << endl;
				foutapp << "Testing STCF() without preemption..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.STCF(NO, list_head);
				break;
		case 5:
				cout << "------------------------ Testing STCF() with preemption ------------------------" << endl;
				foutapp << "Testing STCF() with preemption..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.STCF(YES, list_head);
				break;
		
		default:
				cout << "------------------------ Testing FCFS ------------------------" << endl;
				foutapp << "Testing FCFS..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.FCFS();

				cout << "------------------------ Testing RR with Time Slice : 3 ------------------------" << endl;
				foutapp.open("results.txt", ios::app);
				foutapp << endl << "Testing RR(3)..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.RR(3, list_head);

				cout << "------------------------ Testing RR with Time Slice : 6 ------------------------" << endl;
				foutapp.open("results.txt", ios::app);
				foutapp << endl << "Testing RR(6)..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.RR(6, list_head);

				cout << "------------------------ Testing STCF() without preemption ------------------------" << endl;
				foutapp.open("results.txt", ios::app);
				foutapp << endl << "Testing STCF() without preemption..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.STCF(NO, list_head);
	
				cout << "------------------------ Testing STCF() with preemption ------------------------" << endl;
				foutapp.open("results.txt", ios::app);
				foutapp << endl << "Testing STCF() with preemption..." << endl << endl;
				foutapp.close();
				firstTime = 1;
				p1.STCF(YES, list_head);

				cout << "DONE ALL ALGORITHMS!" << endl;
				foutapp.open("results.txt", ios::app);
				foutapp << endl << "DONE ALL ALGORITHMS!" << endl;
				foutapp.close();
				cout << "Cleaning up deviceQ, runningQ, readyQ and poolQ" << endl;
				break;
	}
	return 0;
}


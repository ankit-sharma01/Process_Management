#pragma warning(disable: 4244)
#include <iostream>
#include <time.h>				// time(NULL)
#include <stdlib.h>				// rand, srand

#define CPUBOUND	0
#define IOBOUND		1

int total_count;
int cpubound_count;
int iobound_count;
double iotime_ratio;

using namespace std;

struct pcb_gen
{
	int pid;
	char type[10];
	int priority;
	int burst_length;
	int numberofIOs;
	int block_time[20];
	int block_length[10];
};
struct process_list
{
	pcb_gen *process;
	process_list *next;
};
class ProcessGenerator
{
	public:
			ProcessGenerator();
			process_list* generate_pool(int total_processes, double ratio);
			int generate_process(int process_type);
			int insert_blocks_iobound(pcb_gen *&this_process);
			int insert_blocks_cpubound(pcb_gen *&this_process);
			int insert_process(const pcb_gen *this_process);
			int print_process_pool();
	private:
			int pid_counter;
			process_list *head;
			process_list *tail;

};
ProcessGenerator::ProcessGenerator()
{
	srand(time(NULL));
	pid_counter = 1;
	head = NULL;
	tail = NULL;
}
int ProcessGenerator::generate_process(int process_type)
{
	pcb_gen *new_process;

	new_process = new pcb_gen();
	
	int rvalue;
	new_process->pid = pid_counter;
	
	if (process_type == CPUBOUND)
		strcpy(new_process->type,"CPU Bound");
	else
		strcpy(new_process->type, "IO Bound");

	new_process->priority = rand() % 10 + 1;
	new_process->burst_length = rand() % 19 + 2;
	if (process_type==CPUBOUND)
		rvalue = insert_blocks_cpubound(new_process);
	else
		rvalue = insert_blocks_iobound(new_process);
	if (rvalue != 0)
	{
		cout << "\nError while inserting blocks\n";
		return -1;
	}
//	cout << "\nProcessGenerator " <<new_process->pid << " Generated" << endl;
//	cout << "number of IOs " << new_process->numberofIOs << endl;
	rvalue = insert_process(new_process);
	if (rvalue != 0)
	{
		cout << "\nError while inserting process\n";
		return -1;
	}
	pid_counter++;
	return 0;
}
int ProcessGenerator::insert_process(const pcb_gen *this_process)
{
	process_list *newNode;
	newNode = new process_list;
	newNode->process = (pcb_gen *)this_process;
	newNode->next = NULL;

	if (head == NULL && tail == NULL)			// First ProcessGenerator
	{
		head = newNode;
		tail = head;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	return 0;
}
int ProcessGenerator::insert_blocks_cpubound(pcb_gen *&this_process)
{
	int blength = this_process->burst_length;
	this_process->numberofIOs = blength / 6;
	int i = 0, start;
	start = rand() % (blength/2) + 1;
	int temp = start;
	while (i < this_process->numberofIOs)
	{
		this_process->block_time[i] = temp;
		this_process->block_length[i] = rand() % 2 + 1;

		if (temp>blength)
		{
			cout << "from cpubound: Error in assigning blocks" << endl;
			cout << "burst time: " << blength << endl;
			cout << "ios: " << this_process->numberofIOs << endl;
			cout << "start: " << start << endl;
			cout << "temp: " << temp << endl;
			return -1;
		}
		i++;
		temp += 4;
	}
	return 0;
}
int ProcessGenerator::insert_blocks_iobound(pcb_gen *&this_process)
{
	int num;
	int blength = this_process->burst_length;
	switch (blength)
	{
		case 1:
		case 2:
			num = 0;
			break;
		case 3:
			num = 1;
			break;
		case 4:
			num = 2;
			break;
		default:
			num = blength / 2.5;
			break;
	}
	this_process->numberofIOs = num;
	int i = 0, start;
	if (blength<6)
		start = 2;
	else
	{
		if (this_process->pid % 2 == 0)
			start = 2;
		else
			start = 3;
	}
	int temp = start;
	while (i < num)
	{
		this_process->block_time[i] = temp;
		if (this_process->numberofIOs  < 3)
			this_process->block_length[i] = rand() % 3 + 5;
		else
			this_process->block_length[i] = rand() % 4 + 7;
		if (temp>blength)
		{
			cout << "\n\nError in assigning blocks\n";
			cout << "from iobound: Error in assigning blocks" << endl;
			cout << "burst time: " << blength << endl;
			cout << "ios: " << this_process->numberofIOs << endl;
			cout << "start: " << start << endl;
			cout << "temp: " << temp << endl;
			return -1;;
		}
		i++;
		temp += 2;
	}
	return 0;
}
int ProcessGenerator::print_process_pool()
{
	int io_cycles, total_cycles, pcount = 0 ;
	double ratio, avg, total=0;
	process_list *p;
	p = head;
	while (p != NULL)
	{
		io_cycles = 0;
		total_cycles = 0;
		ratio = 0;
		cout << endl << "----" << endl;
		cout << "Process " << p->process->pid << endl;
		cout << "Type : " << p->process->type << endl;
		cout << "Priority " << p->process->priority << endl;
		cout << "Burst Length " << p->process->burst_length << endl;
		cout << "Number of Blocks " << p->process->numberofIOs << endl;
		for (int i = 0; i < p->process->numberofIOs; i++)
		{
			io_cycles = io_cycles + p->process->block_length[i];
	//		cout << "Blocks at " << p->process->block_time[i] << "for " << p->process->block_length[i] << endl;
		}
		total_cycles = p->process->burst_length + io_cycles;
		cout << "iocycles: " << io_cycles << " total cycles: " << total_cycles << endl;
		ratio = static_cast<double>(io_cycles) / total_cycles;
		total = total + ratio;
		cout << "Ratio: " << ratio << endl;
		p = p->next;
		pcount++;
	}
	avg = total / pcount;
	iotime_ratio = avg * 100;
	cout << "\nAverage Ratio: " << iotime_ratio << endl;
	return pcount;
}
process_list* ProcessGenerator::generate_pool(int total_process, double ratio)
{
	int cpu_generated = 0, io_generated = 0;
	int gen_counter = 0;;
	int rvalue;

	iobound_count = (total_process*ratio) / 100;
	cpubound_count = total_process - iobound_count;
/*
	cout << "\nTotal Process : " << total_process << endl;
	cout << "CPU Bound : " << cpubound_count << endl;
	cout << "IO Bound : " << iobound_count << endl;
*/
	for (gen_counter = 0; gen_counter <= total_process; gen_counter++)
	{
		if (gen_counter % 2 == 0)
		{
			if (cpu_generated < cpubound_count)
			{
				rvalue = generate_process(CPUBOUND);
				if (rvalue == 0)
					cpu_generated++;
			}
			else if (io_generated < iobound_count)
			{
				rvalue = generate_process(IOBOUND);
				if (rvalue == 0)
					io_generated++;
			}
		}
		else 
		{
			if (io_generated < iobound_count)
			{
				rvalue = generate_process(IOBOUND);
				if (rvalue == 0)
					io_generated++;
			}
			else if (cpu_generated < cpubound_count)
			{
				rvalue = generate_process(CPUBOUND);
				if (rvalue == 0)
					cpu_generated++;
			}
		}
	}
	
	total_count = print_process_pool();
	if (total_count != (cpu_generated + io_generated))
	{
		cout << "\nAlert! Mismatch in number of processes generated and processes inserted in the list." << endl;
	}
	cpubound_count = cpu_generated;
	iobound_count = io_generated;

	cout << "\n\nTotal " << cpu_generated + io_generated << " processes generated" << endl;
	cout << "CPU Bound : " << cpu_generated << endl;
	cout << "\nIO Bound : " << io_generated << endl;;

	return head;
}
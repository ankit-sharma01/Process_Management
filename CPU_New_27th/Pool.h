/*
	To generate Process mix and write it to a file
*/
#include <iostream>
#include <time.h>				// time(NULL)
#include <stdlib.h>				// rand, srand
#include "Process.h"

int cpubound_count;
int iobound_count;
int total_count;
double iotime_ratio;

#define TRUE		0
#define FALSE		1

#define DEFAULT		20
#define BURSTLIMIT	20

#define NORMAL		0
#define TIGHT		1
#define HIGH		1

using namespace std;

class Pool
{
	public:
			Pool();
			Pool(int process_count, int given_mixture);
			void generate();
			int write_to_file();
	private:
			int total_process;
			int burst_limit;		// burst time of longest process
			int process_mix;		// 0-normal mix 1-cpu bound 2-io bound
			int cpu_bound;			// number of cpu bound processes
			int io_bound;			// number of io bound processes
};
Pool::Pool()
{
	total_process = DEFAULT;
	burst_limit = BURSTLIMIT;
	process_mix = EQUAL;
	cpu_bound = DEFAULT / 2;
	io_bound = DEFAULT - cpu_bound;
}
Pool::Pool(int process_count, int given_mixture)
{
	total_process = process_count;
	process_mix = given_mixture;
	burst_limit = BURSTLIMIT;
}
void Pool::generate()
{
	int other_type, other_type_count, process_mix_count;
	int main_counter=1;
	int other_counter=1;

	int counter = 1, rvalue;

	Process p;

	if (process_mix == EQUAL)									// Equal Mix
	{
		cpu_bound = total_process / 2;
		io_bound = total_process - cpu_bound;
	}
	else
	{
		process_mix_count = total_process*(0.8);				// 80% processes will be given type processes
		other_type_count = total_process - process_mix_count;	// 20% processes will be other type processes
		
		if (process_mix == CPUBOUND)
		{
			other_type = IOBOUND;
			cpu_bound = process_mix_count;
			io_bound = other_type_count;
		}
		else													// IO Bound
		{
			other_type = CPUBOUND;
			cpu_bound = other_type_count;
			io_bound = process_mix_count;
		}
		cout << "\nCPU Bound: " << cpu_bound << endl;
		cout << "Io Bound: " << io_bound << endl;
		cout << "Total: " << cpu_bound + io_bound << endl;
		
		for (int i = 1; i <= total_process; i++)
		{
			if (counter % 4 == 0 && (other_counter <= other_type_count))
			{
				rvalue = p.generate_process(other_type);
				if (rvalue == 0)
				{
					counter++;
					other_counter++;
				}
			}
			else if (main_counter <= process_mix_count)
			{
				rvalue = p.generate_process(process_mix);
				if (rvalue == 0)
				{
					counter++;
					main_counter++;
				}
			}
		}
	}
//	cout << "\n\nTotal " << counter-1 << "processes generated.\n";
//	cout << "Main Type : " << process_mix << " count: " << main_counter-1;
//	cout << "\nOther Type : " << other_type << " count: " << other_counter-1 << "\n\n";
	
	iotime_ratio=p.print_process_pool(total_process);
	total_count = cpu_bound + io_bound;
	cpubound_count = cpu_bound;
	iobound_count = io_bound;
	return;
}
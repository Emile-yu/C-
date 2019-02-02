#include <iostream>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[])
{
	int i, n;
	int tid;
	#pragma omp parallel num_threads(2) private(tid)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				tid = omp_get_thread_num();
				cout<<"tid = "<<tid<<endl;
			}

			#pragma omp section
			{
				tid = omp_get_thread_num();
				cout<<"tid = "<<tid<<endl;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[])
{
	int i, n, tid;
	n = 12;
	#pragma omp parallel num_threads(2) private(tid)
	{
		tid = omp_get_thread_num();
		#pragma omp for schedule(static,2)
		for(i=0;i<n;i++) {
			cout<<"tid : "<<tid<<" = [ "<<i<<" ]"<<endl;
		}
	}
	return 0;
}
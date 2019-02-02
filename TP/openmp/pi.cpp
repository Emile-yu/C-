#include <iostream>
#include <stdlib.h>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[])
{
	int i,n,tid;
	double step, x, pi, *sum;

	n = 4;
	omp_set_num_threads(n);
	step = 1.0/(double)n;
	sum = (double*)calloc(n, sizeof(double));

	#pragma omp parallel private(tid,x)
	{
		tid = omp_get_thread_num();
		#pragma omp for
		for(i=0;i<n;i++) {
			x = (i+0.5)*step;
			sum[tid]+=4/(1+x*x);
		}

	}
	for(i=0;i<n;i++) {
		pi+=sum[i]*step;
	}
	cout<<"pi = "<<pi<<endl;
	return 0;
}
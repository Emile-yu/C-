#include <iostream>
#include <omp.h>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[])
{
	int size, my_rank;
	int i, n, start, end;
	double step, x, sum, pi;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

	n = 1000;
	step = 1.0/(double)n;
	sum = 0.0;
	start = my_rank*n/size;
	end = (my_rank+1)*n/size;

	#pragma omp parallel num_threads(4) private(x)
	{
		#pragma omp for reduction(+:sum)
		for(i=start;i<end;i++) {
			x = (i+0.5)*step;
			sum+=4/(1+x*x);
		}
	}

	MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(0 == my_rank) {
		pi = pi*step;
		cout<<"pi = "<<pi<<endl;
	}
	MPI_Finalize();
	return 0;
}
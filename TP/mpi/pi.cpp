#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char 	*argv[])
{
	int size, my_rank;
	int i, n;
	double x, step, sum, pi;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

	n = 1000;
	step = 1.0/(double)n;
	sum = 0.0;

	cout<<"my_rank"<<my_rank<<endl;
	for(i = my_rank;i<n;i+=size) {
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	sum = sum*step;
		
	MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(0 == my_rank) {
		cout<<"pi = "<<pi<<endl;
	}
	MPI_Finalize();
	return 0;
}
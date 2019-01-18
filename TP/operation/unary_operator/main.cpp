#include <iostream>
#include "Coordinate.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Coordinate coor1(1,3);
	cout<<coor1.getX()<<","<<coor1.getY()<<endl;
	++coor1;
	cout<<coor1.getX()<<","<<coor1.getY()<<endl;

	cout<<(coor1++).getX()<<endl;

	cout<<coor1.getX()<<","<<coor1.getY()<<endl;

	return 0;
}
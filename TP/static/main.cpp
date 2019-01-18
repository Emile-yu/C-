#include <iostream>
#include "Tank.h"
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<Tank::getCount()<<endl;

	Tank t1('A');

	cout<<Tank::getCount()<<endl;

	Tank *t2 = new Tank('B');

	cout<<t2->getCount()<<endl;

	delete t2;

	cout<<Tank::getCount()<<endl;

	return 0;
}
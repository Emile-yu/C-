#ifndef COORDINATE_H_
#define COORDINATE_H_
#include <iostream>
using namespace std;

class Coordinate
{
public:
	Coordinate(int x=0, int y=0);
	friend ostream& operator<<(ostream& o, const Coordinate& c);
private:
	int m_iX;
	int m_iY;
	
};
#endif
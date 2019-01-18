#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y) {
	m_iX = x;
	m_iY = y;
}



ostream& operator<<(ostream& o, const Coordinate& c) {
	o<<"("<<c.m_iX<<","<<c.m_iY<<")"<<endl;
	return o;
}
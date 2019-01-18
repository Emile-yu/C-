#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y):m_iX(x),m_iY(y){}

Coordinate &Coordinate::operator++() {
	m_iX++;
	m_iY++;
	return *this;
}

Coordinate Coordinate::operator++(int) {
	Coordinate old(*this);
	this->m_iX++;
	this->m_iY++;
	return old;
}
#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate
{
public:
	Coordinate(int x, int y);
	Coordinate &operator++();//前置

	Coordinate operator++(int);//后置

	int getX() {return m_iX;}
	int getY() {return m_iY;}
private:
	int m_iX;
	int m_iY;
};
#endif
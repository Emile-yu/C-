#include<iostream>
#include"Points2D.h"
using namespace std;

double Points2D::getX() {
	return x;
}

double Points2D::getY() {
	return y;
}

Points2D::Points2D(double vx, double vy) {
	x= vx;
	y= vy;
}

Points2D::~Points2D() {
	cout<<"destruction d'un point"<<endl;
}

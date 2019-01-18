
#ifndef SOMMET_H_
#define SOMMET_H_
#include<iostream>
#include<sstream>
#include"GElement.h"
using namespace std;

template<class T>

class Sommet:public GElement
{
public:
	int degre;
	T v;

	Sommet(const int clef,const T &v);

	int getDegre()const;

	T getV()const;
    
	bool operator==(const Sommet<T>* s);

	operator string() const;


};


template<class T>
Sommet<T>::Sommet(const int clef,const T &v):GElement(clef),v(v),degre(0){}

template<class T>
int Sommet<T>::getDegre() const
{
	return degre;
}

template<class T>
T Sommet<T>::getV() const
{
	return v;
}

template<class T>
Sommet<T>::operator string()const
{
	ostringstream os;
	os<<"Sommet ("<<endl;
	os<<GElement::operator string()<<endl;
	os<<"degre= " <<degre<<endl;
	os<<"v= "<<v<<endl;
	os<<" )"<<endl;;
	return os.str();
}

template<class T>
bool Sommet<T>::operator==(const Sommet<T>* s) {
	return s->clef == this->clef;
}

template<class T>
ostream & operator <<(ostream &o,const Sommet<T> &s)
{
	return o<<(string)s;
}

#endif
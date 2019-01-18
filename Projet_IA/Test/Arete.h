#ifndef ARETE_H_
#define ARETE_H_
#include<iostream>
#include<sstream>
#include"GElement.h"
#include"Sommet.h"
using namespace std;

template<class S,class T>

class Arete:public GElement
{
public:
	Sommet<T> *debut;
	Sommet<T> *fin;
	S v;

	Arete(int clef, Sommet<T> * debut, Sommet<T> * fin, const S & v):
    GElement(clef),debut(debut),fin(fin),v(v){}


	bool estEgal(const Sommet<T> *s1 ,const Sommet<T> *s2) const;

	operator string() const;
};



template<class S,class T>
Arete<S,T>::operator string() const
{
	ostringstream os; 
	os <<"Arete ("<<endl;
	os <<GElement::operator string()<<endl;
	os << "clef debut= " << debut->clef<<endl;
    os << "clef fin= " << fin->clef <<endl;
	os << "v= " << v <<endl;
    os << ")"<<endl;
 
	return os.str();
}
template<class S,class T>
bool Arete<S,T>::estEgal(const Sommet<T> *s1 ,const Sommet<T> *s2) const {
	return (s1 == debut && s2 == fin) || (s1 == fin && s2 == debut);
}


template <class S, class T>
ostream & operator << (ostream & os, const Arete<S,T> & arete)
{
return os << (string) arete;
}

#endif
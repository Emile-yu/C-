#pragma once
#include<iostream>
#include"Langues.h"
using namespace std;
class Artiste
{
private:
	string _nom;
	Langues::langues langue;
public:
	Artiste(const string& nom,Langues::langues langue= Langues::All);

	const string& getnom() const{return _nom;}

	void setnom(const string& nom) {_nom=nom;}

	Langues::langues getLangue() const{return langue;}

	friend ostream&	operator<<(ostream&, const Artiste&);
	
};
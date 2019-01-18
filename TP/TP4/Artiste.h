#pragma once
#include<iostream>
#include<string>
#include"Langues.h"
using namespace std;

class Artiste
{
private:
	string _nom;
	Langues::langues langue;
public:
	Artiste(const string& nom, Langues::langues langue);
	const string& getNom() const{return _nom;}
	void setNom(const string& nom) {_nom=nom;}
	Langues::langues getLangue() const{return langue;}
	friend ostream& operator<<(ostream&, const Artiste&);
	//bool operator<(const Artiste a)const {return  _nom< a._nom;}
	friend bool operator<(const Artiste& a1, const Artiste& a2) {return  a1._nom< a2._nom;}
};
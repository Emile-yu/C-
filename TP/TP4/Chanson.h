#pragma once
#include<iostream>
#include<string>
#include<map>
#include<set>
#include"Langues.h"
#include"Artiste.h"
using namespace std;
class Chanson
{
private:
	const string _titre;
	Langues::langues langue;
	double _duree;
	map<string, Artiste*>_art;
public:
	Chanson(const string& titre, const double duree, Langues::langues langue);

	bool hasArtiste(Artiste*);

	int getNombreArtistes();

	void addArtiste(Artiste*);

	set<Artiste*> getArtistes();

	string getTitre() {return _titre;}

	double getDuree() {return _duree;}

	Langues::langues getLangue() const{return langue;}

	friend ostream&	operator<<(ostream &o, const Chanson &c);
	
};
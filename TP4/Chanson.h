#pragma once
#include<iostream>
#include<string>
#include"Artiste.h"
#include"Langues.h"
#include<map>
#include<set>
using namespace std;
class Chanson
{
private:
	string _titre;
	Langues::langues langue;
	double _duree;
	map<string,Artiste*> _art;
public:
	Chanson(const string& titre,double duree,Langues::langues langue= Langues::All);


	virtual ~Chanson(){}
	
	const string& gettitre()const {return _titre;}

	void settitre(const string& titre) {_titre=titre;}

	double getduree() const {return _duree;};

	void setduree(const double duree) {_duree=duree;}

	Langues::langues getLangue() const{return langue;}

	bool hasArtiste(Artiste *a);

	int getNombreArtistes();

	void addArtiste(Artiste *a);

	set<Artiste*>getArtistes();

	friend ostream&	operator<<(ostream &o, const Chanson &c);


};
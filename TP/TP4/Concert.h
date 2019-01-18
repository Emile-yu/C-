#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Chanson.h"
#include"Artiste.h"
using namespace std;

class Concert
{
private:
	string _nom;
	string _date;
	vector<Chanson*> _cha;
public:
	Concert(const string& nom, const string& date);

	void addChanson(Chanson*);

	set<Artiste*> getArtistes()const;

	double getDuree();

	const string& getNom()const {return _nom;}

	const string& getDate()const {return _date;}

	void afficher();

	friend ostream& operator<<(ostream &o, const Concert &c);
};
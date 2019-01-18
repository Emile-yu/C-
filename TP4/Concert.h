#pragma once
#include<iostream>
#include<vector>
#include<set>
class Concert
{
private:
	string _nom;
	string _date;
	vector<Chanson*>_cha;
public:
	Concert(const string& nom,const string& date);

	void Vider();

	virtual ~Concert() {Vider();};

	void supp(int i);
	
	const string& getnom()const {return _nom;}

	void setnom(const string& nom) {_nom=nom;}

	const string& getdate()const {return _date;}

	void setdate(const string& date) {_date=date;}

	set<Artiste*>getArtiste() const;

	int getNombreChansons() const;

	void addChanson(Chanson* c);

	double getDuree() const;

	friend ostream &operator<<(ostream &o, const Concert &c);
};
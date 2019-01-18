#pragma once
#include <iostream>
#include <string>
#include "Diplome.h"
using namespace std;
class Diplome;
class Etudiant {
private :
	char *_nom;
	int _age;
	bool _boursier;
	Diplome *_diplome;
	Etudiant(const char *nom,int age,bool boursier,Diplome *diplome)
	{
		if(nom!=NULL) {
			_nom=strdup(nom);
		}

		_age=age;
		_boursier=boursier;
		if(diplome!=NULL)
		{
			_diplome=diplome;
		}

		
	}
	Etudiant (const Etudiant &e) {abort();}
	
	~Etudiant() {delete _nom;};

	void operator =(const Etudiant &e){abort();};

	void setnom(const char *nom){
		if(nom!=NULL){
			delete _nom;
			_nom=strdup(nom);
	};
   friend class Diplome;
public:
	

    Diplome * getDiplome() const{return _diplome;}

	const char *getNom() const{ return _nom;}

	int getage() const{return _age;}

	bool getbourisier() const {return _boursier;}

	void setage(int age) {_age=age;}

	void setboursier(bool boursier) {_boursier=boursier;}

	bool operator==(const Etudiant &e) const {
		return ((!strcmp(e.getNom(),_nom)) && (e.getage()==_age) && (e.getbourisier()==_boursier));
	}
};
ostream & operator<<(ostream &o,const Etudiant &e);
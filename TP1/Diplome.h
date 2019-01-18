#pragma once
#include <iostream>
#include <string.h>
#include "Stage.h"
#include "Etudiant.h"
#include "Option.h"
using namespace std;
class Option;
class Etudiant;
class Diplome
{
private:
	char *_titre;
	Stage *_stage;
	
	static const int Max_ETUDIANTS=50;
	Etudiant* _inscrits[Max_ETUDIANTS];
	Option* _option[100];
	int _effectif;
	int _nb;
	//void deinscrire(const Etudiant &);
	//Diplome(const Diplome &d) {abort();};
	//void operator = (const Diplome &d) {abort();};
public:
	Diplome (char *titre,Stage *stage):_effectif(0),_nb(0) {_titre=strdup(titre);_stage=stage;}

	~Diplome() 
	{
		delete _titre;
		for(int i=0;i<_effectif;i++)
		{
			delete _inscrits[i];
		}
		_effectif=0;
	}

	int geteffectif()const {return _effectif;}

	int getnb() const {return _nb;}

	const char *gettitre() const {return _titre;}

	void settitre(const char *titre) {
		delete(_titre);
		_titre=strdup(titre);
	}
	const Stage *getstage() const {return _stage;}

	void ajouter ( Option &o)
	{
		_option[_nb++]=&o;
	}

	void setstage(const Stage &s) {
	
		if(_stage)
		{
			delete(_stage);
		}
		_stage=new Stage(s);
	}

	Etudiant &inscrire(char *nom,int age,bool boursier);

	void inscrire(Etudiant &e);

	void deinscrire(const Etudiant &e);

	Option & operator[] (int i)
   	{

	   return *_option[i];
    }
   
   /*const Etudiant & operator[] (int i)
	{
		if ((i < 0) || (i >= _effectif))
			abort();

		return *_inscrits[i];
	}*/
};
ostream & operator <<(ostream &o,const Diplome &d);



#include <iostream>
#include <string.h>
#include "Etudiant.h"
#include "Diplome.h"
using namespace std;
class Etudiant;
class Diplome;
class Option
{
private:
	char *_nom;
	static const int effectifMax=100;
	Etudiant *_e[effectifMax];
	int _nb;
public:
	Option(char *nom):_nb(0){_nom=nom;}

	Option(const Option &o)
	{
		_nom=strdup(o._nom);
		_nb=o._nb;
		for(int i=0;i<_nb;i++)
		{
			_e[i]=o._e[i];
		}
	}

	~Option()
	{
		delete _nom;
		_nb=0;
	}

	const char *getnom() const {return _nom;}

	void setnom(const char *nom) {_nom=strdup(nom);}

	int getnb() const{return _nb;}

	void setnb(int nb){_nb=nb;}
	
	void ajouter (Etudiant *e)
	{
		_e[_nb++]=e;
	}

	const Etudiant & operator[](int i)
	{
		return *_e[i];
	}

	const Option &operator =(const Option &o)
	{
		if(this!=&o)
		{
			delete _nom;
			_nb=0;

			_nom=strdup(o._nom);
			_nb=o._nb;
			for(int i=0;i<_nb;i++)
			{
				_e[i]=o._e[i];
			}
		}
		return *this;
	}
};
extern ostream & operator << (ostream &s, const Option &o);

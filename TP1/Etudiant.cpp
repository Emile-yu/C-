#include "Etudiant.h"
#include "Diplome.h"
ostream & operator<<(ostream &o,const Etudiant &e){
	o<<"Nom :"<<e.getNom()<<endl;
	o<<"Age :"<<e.getage()<<endl;
	o<<"Boursier :"<<e.getbourisier()<<endl;
	o<<"Diplome :"<<*e.getDiplome()<<endl;
	return o;
}
#include "Diplome.h"
#include "Etudiant.h"
#include "Stage.h"
Etudiant & Diplome::inscrire(char *nom,int age,bool boursier) {
		if(_effectif==Max_ETUDIANTS)
		{
			abort();
		}
		Etudiant *e=new Etudiant(nom,age,boursier,this);
		_inscrits[_effectif++]=e;
		return *e;
	}

void Diplome::inscrire(Etudiant &e) {
	if(_effectif==Max_ETUDIANTS)
	{
		abort();
	}
	(e._diplome)->deinscrire(e);
	e._diplome=this;
	_inscrits[_effectif++]=&e;
}
void Diplome::deinscrire(const Etudiant &e){
	int pt=0;
	bool b=false;
	while(!b){
		if(_inscrits[pt]==&e)
		{
			b=true;
		}
		pt++;
	}
	_inscrits[pt]=_inscrits[_effectif-1];
	_effectif--;
}

ostream & operator<<(ostream &o,const Diplome &d)
{
	o<<"Titre :"<<d.gettitre()<<endl;
	    
	return o;
}
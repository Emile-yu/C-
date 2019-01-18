#include"Chanson.h"
#include<algorithm>
#include<iostream>

Chanson::Chanson(const string& titre,double duree,Langues::langues l):_titre(titre),_duree(duree),langue(l){}


bool Chanson::hasArtiste(Artiste *a)
{
	map<string,Artiste*>::iterator trouve=_art.find(a->getnom());
	if(trouve==_art.end())
		return false;
	return true;
}
int Chanson::getNombreArtistes()
{
	int nb=0;
	for(map<string,Artiste*>::iterator it=_art.begin();it!=_art.end();++it)
	{
		nb++;
	}
	return nb;
}

void Chanson::addArtiste(Artiste *a)
{
	map<string,Artiste*>::iterator trouve=_art.find(a->getnom());
	if(trouve==_art.end())
	{
		_art[a->getnom()]=a;
	}
}

set<Artiste*>Chanson::getArtistes()
{
	set<Artiste*>s;
	for(map<string,Artiste*>::iterator it=_art.begin();it!=_art.end();++it)
	{
		s.insert(it->second);
	}
	return s;
}
class Affichier
{
//private:
	//ostream &flux;
public:
	//Affichier(ostream & f):flux(f){}
	void operator()(pair<string,Artiste*>p)
	{
		cout<<p.second->getnom()<<endl;
	}
};
ostream &	operator<<(ostream &o, const Chanson &c)
{
	o<<"Titre :"<<c.gettitre()<<endl;
	o<<"Langue :"<<Langues::init(c.getLangue())<<endl;
	o << "Liste des artistes " << endl;
	o << "------------------------------" << endl;
	for_each(c._art.begin(),c._art.end(),Affichier());
	return o;
}
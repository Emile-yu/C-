#include"Concert.h"

Concert::Concert(const string& nom,const string& date):_nom(nom),_date(date){}

void Concert::Vider()
{
	for(int i=0;i<_cha.size();i++)
	{
		delete _cha[i];
	}
	_cha.clear();
}

void Concert::supp(int i)
{
	int nb=_cha.size();
	if(i<nb)
	{
		_cha[i]=_cha[nb-1];
		_cha.pop_back();
	}
}

set<Artiste*> Concert::getArtiste() const
{
	set<Artiste*>s;
	for(int i=0;i<_cha.size();i++)
	{
		set<Artiste*> lesArtiste=_cha[i]->getArtistes();
		set<Artiste*>::iterator it=lesArtiste.begin();
		while(it!=lesArtiste.end())
		{
			s.insert(*it);
			it++;
		}
	}
	return s;
}

int  Concert::getNombreChansons() const
{
	return _cha.size();
}

void  Concert::addChanson(Chanson* c)
{
	_cha.push_back(c);
}

double  Concert::getDuree()const
{
	double somme=0;
	for(int i=0;i<_cha.size();i++)
	{
		somme=somme+_cha[i]->getduree();
	}
	return somme;
}

ostream& operator<<(ostream &o,const Concert &c)
{
	o<<"Nom :"<<c.getnom()<<endl;
	o<<"Date :"<<c.getdate()<<endl;
	o << "Liste des Chansons" << endl;
	o << "------------------------------" << endl;
	set<Artiste*> lesArtiste=c.getArtiste();
	set<Artiste*>::const_iterator it=lesArtiste.begin();
	while(it!=lesArtiste.end())
	{
		o<<**it<<endl;
	    it++;
	}
	
    return o;
}

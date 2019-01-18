#include"Concert.h"

Concert::Concert(const string& nom, const string& date):_nom(nom),_date(date){}

void Concert::addChanson(Chanson* c) {
	_cha.push_back(c);
}

set<Artiste*> Concert::getArtistes()const {
	set<Artiste*> a;
	for(int i=0;i<_cha.size();i++) {
		set<Artiste*> list = _cha[i]->getArtistes();
		set<Artiste*>::iterator it=list.begin();
		while(it != list.end()) {
			a.insert(*it);
			it++;
		}
	}
	return a;
}

double Concert::getDuree() {
	double nb=0;
	for(int i=0;i<_cha.size();i++) {
		nb = nb + _cha[i]->getDuree();
	}
	return nb;
}

void Concert::afficher() {
	set<Artiste*> list = _cha[0]->getArtistes();
	set<Artiste*>::iterator it = list.begin();
	cout<<*it<<endl; 
	
}

ostream& operator<<(ostream &o, const Concert &c) {
	o<<"Nom :"<<c.getNom()<<endl;
	o<<"Date :"<<c.getDate()<<endl;
	o << "Liste des Chansons" << endl;
	o << "------------------------------" << endl;
	set<Artiste*> lesArtiste=c.getArtistes();
	set<Artiste*>::const_iterator it=lesArtiste.begin();
	while(it!=lesArtiste.end())
	{
		o<<**it<<endl;
	    it++;
	}
	
    return o;
}
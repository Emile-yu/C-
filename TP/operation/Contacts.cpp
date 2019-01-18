#include <iostream>
#include <string.h>
#include "Contacts.h"
#include "Telephones.h"
using namespace std;

Contacts::Contacts(char* _nom, char* _prenom) {
	nom = strdup(_nom);
	prenom = strdup(_prenom);
	nb = 0;
}

Contacts::Contacts(const Contacts& c){
	nom = strdup(c.nom);
	prenom = strdup(c.prenom);
	nb = c.nb;
	for(int i=0;i<c.nb;i++) {
		tels[i] = c.tels[i];
	}
	cout<<"Con"<<endl;
}

Contacts::~Contacts() {
	delete nom;
	delete prenom;
	
	for(int i=0;i<nb;i++) {
		//delete tels[i];			
	}
	nb = 0;
	cout<<"Contacts"<<endl;
}

void Contacts::supprime(int num) {
	for(int i=num;i<nb;i++) {
		tels[i] = tels[i++];
	}
	nb--;
}

Contacts& Contacts::operator+(Telephones& t) {

	this->tels[nb++] = &t;
	return *this;
	
}
/*Contacts& operator+(Contacts& c,Telephones& t) {
	Contacts c1(c);
	Telephones t1 = t;
	c1.tels[(c1.nb)++] = &t1;
	return c1;
}*/

Contacts& Contacts::operator=(const Contacts& c) {

	if(this!=&c) {
		delete nom;
		delete prenom;
		nom = strdup(c.nom);
		prenom = strdup(c.prenom);
		nb = c.nb;
		for(int i=0;i<c.nb;i++) {
			tels[i] = c.tels[i];
		}
		cout<<"duplica"<<endl;
	}
	return *this;
}

ostream& operator<<(ostream& o, const Contacts& c) {
	o<<"Nom:"<<c.getNom()<<", Prenom:"<<c.getPrenom()<<endl;
	/*for(int i=0;i<c.;i++) {
		o<<c.tels[i]<<endl;
	}*/
	return o;
}

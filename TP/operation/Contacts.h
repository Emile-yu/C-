#ifndef CONTACTS_H_
#define CONTACTS_H_
#include <iostream>
using namespace std;
class Telephones;
class Contacts
{
public:
	
	Contacts(char* _nom="", char* _prenom="");
	Contacts(const Contacts& c);
	~Contacts();
	char* getNom() const {return nom;}
	void setNom(const char* _nom) {
		delete nom;
		nom = strdup(_nom);
	}
	char* getPrenom() const {return prenom;}
	void setPrenom(const char* _prenom) {
		delete prenom;
		nom = strdup(_prenom);
	}

	int getNb() const {return nb;}
	void supprime(int num);
	Contacts& operator+(Telephones& t);
	
	Contacts& operator=(const Contacts& c);
	
	//friend Contacts& operator+(Contacts& c,Telephones& t);
	Telephones& operator[] (int i) {
		return *tels[i];
	}
	
private:
	char* nom;
	char* prenom;
	int nb;

	static const int Max_TELEPHONES = 10;
	Telephones* tels[Max_TELEPHONES];
};

extern ostream& operator<<(ostream& o, const Contacts& c);
#endif

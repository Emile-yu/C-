#include"Artiste.h"

Artiste::Artiste(const string& nom,Langues::langues l):_nom(nom),langue(l){}


ostream& operator<<(ostream& out, const Artiste& artiste) {
	out << "Artiste[" << artiste._nom << ";" << Langues::init (artiste.langue) << "]";
	return out;
}
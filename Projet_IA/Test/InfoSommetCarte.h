#ifndef INFOSOMMETCARTE_H_
#define INFOSOMMETCARTE_H_
#include "Vecteur2D.h"
class InfoSommetCarte
{
public:
	string nom;
	Vecteur2D position;
public:
	InfoSommetCarte(const string& _nom, const Vecteur2D& _position);

	operator string() const;
	
};
ostream& operator<<(ostream& o, const InfoSommetCarte& i);
#endif
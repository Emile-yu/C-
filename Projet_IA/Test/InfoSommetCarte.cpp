#include <iostream>
#include <sstream>
#include "InfoSommetCarte.h"
using namespace std;

InfoSommetCarte::InfoSommetCarte(const string& _nom, const Vecteur2D& _position):nom(_nom),position(_position){}

InfoSommetCarte::operator string() const {
	ostringstream oss;
	oss<<"nom :"<<this->nom<<", position :"<<this->position<<endl;
	return oss.str();
}

ostream& operator<<(ostream& o, const InfoSommetCarte& i) {
	return o<<(string)i;
}
#ifndef INFOARETECARTE_H_
#define INFOARETECARTE_H_
#include <iostream>
using namespace std;
class InfoAreteCarte
{
public:
	double cout;
public:
	InfoAreteCarte(const double& _cout);
	
	operator string() const;
	
};
ostream& operator<<(ostream& o, const InfoAreteCarte& i);
#endif
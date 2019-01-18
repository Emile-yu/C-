#ifndef GELEMENT_H_
#define GELEMENT_H_
#include <iostream>
using namespace std;
class GElement
{
public:
	int clef;//相当于index
public:
	GElement(const int _clef);

	virtual operator string() const;
	

};
ostream& operator<<(ostream& o, const GElement& g);
#endif
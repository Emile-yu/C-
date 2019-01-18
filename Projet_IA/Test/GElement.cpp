#include <iostream>
#include "GElement.h"
#include "sstream"
using namespace std;

GElement::GElement(const int _clef):clef(_clef){}

GElement::operator string() const {
	ostringstream oss;
	oss<<"clef = "<<clef;
	return oss.str();
}

ostream& operator<<(ostream& o, const GElement& g) {
	o<<(string)g<<endl;
	return o;
}
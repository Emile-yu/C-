#include"GElement.h"

GElement::GElement(const int clef):clef(clef){}

GElement::operator string() const
{
	ostringstream oss;
	oss << "clef = " << clef;
	return oss.str();
}


ostream & operator  <<(ostream &o,const GElement &g)
{
	//o<<g.getClef()<<endl;
	o<<(string)g<<endl;
	return o;
}
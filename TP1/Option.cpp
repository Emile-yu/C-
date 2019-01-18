#include "Option.h"
ostream & operator << (ostream &s, const Option &o)
{
	s<<"Nom :"<<o.getnom()<<endl;
	s<<"Nb :"<<o.getnb()<<endl;
	return s;
}
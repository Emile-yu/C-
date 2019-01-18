#include"Chemin.h"

ostream & operator <<(ostream &o,const Chemin &c)
{
	o<<c.getChemin()<<endl;
	return o;
}
#include "Stage.h"
ostream & operator<<(ostream &o,const Stage &s)
{
	o<<"duree min :"<<s.getmin()<<","<<"duree max :"<<s.getmax()<<","<<"evaluation :"<<s.getevalue()<<endl;
	return o;
}
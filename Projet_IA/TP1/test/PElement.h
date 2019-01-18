#include<stdlib.h>
#include<iostream>
#include<ostream>
#include <sstream>
using namespace std;

/*bool compar1(const double *a,const double *b)
{
    return *a <= *b;
}
bool compar2(const string *a,const string *b)
{
	return a->compare(*b)<=0;
}

bool egal(const double *a,const double *b)
{
    return *a == *b;
}*/
template<class T>

class PElement
{
public:
	T *v;
	PElement<T> *s;
public:
	PElement(T *v, PElement<T> *s);

	static int taille(const PElement<T> *l);
	

	static const string toString(const PElement<T> * p);
	

	static void insertionOrdonnee(T * a, PElement<T> * & l, bool (*estPlusPetitOuEgal)(const T * a1, const T * a2));
	
	static void insertion(T *a,PElement<T> * & l);

	static T * depiler(PElement<T> * & l);

	static bool retire(const T * a, PElement<T> * & l);

	static void efface1(PElement<T>* & l);

	static void efface2(PElement<T>* & l);

    const PElement<T> & operator=(PElement<T>* & p);

};
template<class T>
const PElement<T> & PElement<T>::operator=(PElement<T>* & p)
{
	 T *a;
	 PElement<T> *t=p;
	 while(t->s!=NULL)
	 {
		 this->v=t->v;
		 this->s=t->s;
		 this=this->s;
		 t=t->s;
	 }
	 this->s=NULL;
	 return *this;
}


template<class T>
PElement<T>::PElement(T *v1,PElement<T> *s1):v(v1),s(s1){}

template<class T>
int PElement<T>::taille(const PElement<T> *l)
{
	if(l==NULL)
	{
		return 0;
	}
	else
	{
		return 1+PElement<T>::taille(l->s);
	}
}
template<class T>
const string PElement<T>::toString(const PElement<T> * p)
{
	/*ostringstream os; 
	os<<debut;
	while(p!=NULL)
	{
		os<<*p->v<<separateur;
		p=p->s;
	}
	os<<fin;
	return os.str();*/
	PElement<T> * r;
	ostringstream oss;

	for ( r = (PElement<T>* ) p, oss << "("; r; r = r->s)
		oss << *(r->v) << ",";

	oss << ")";
	return oss.str();

}

template<class T>
 void PElement<T>::insertionOrdonnee(T * a, PElement<T> * & l, bool (*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if(l==NULL)
	{
		l=new PElement(a,NULL);
	}
	else if(estPlusPetitOuEgal(a,l->v))
	{

		l=new PElement(a,l);

	}
	else
	{
		insertionOrdonnee(a,l->s,estPlusPetitOuEgal);
	}
}
template<class T>
void PElement<T>::insertion(T *a,PElement<T> * & l)
{
	if(l==NULL)
	{
		l=new PElement(a,NULL);
	}
	else
	{
		insertion(a,l->s);
	}
}

template<class T>
 T * PElement<T>::depiler(PElement<T> * & l)
{
	
	T *a=l->v;
	PElement<T> * tete = l;
	l=l->s;
	delete tete;
	return a;
	
}

template<class T>
 bool PElement<T>::retire(const T * a, PElement<T> * & l)
 {
	 if(!l)
	 {
		 return false;
	 }
	 else if(a==l->v)
	 {
		 PElement<T> *r=l;
		 l=l->s;
		 delete r;
		 return true;
	 }
	 else
	 {
		 return PElement<T>::retire(a,l->s);
	 }
 }

template<class T>
void PElement<T>::efface1(PElement<T>* & l)
{
	if (l)
   {
   PElement<T>::efface1(l->s);
   delete l; l = NULL;
   }

}

 template<class T>
void PElement<T>::efface2(PElement<T>* & l)
{
	if (l)
   {
   PElement<T>::efface2(l->s);
   delete l->v; delete l; l = NULL;
   }

}

template<class T>
ostream & operator<<(ostream & os,const PElement<T> *l)
{
	return os<<PElement<T>::toString(l);
}

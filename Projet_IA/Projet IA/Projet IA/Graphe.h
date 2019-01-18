#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include"GElement.h"
#include"Sommet.h"
#include"Arete.h"
#include"PElement.h"
#include"DessinGraphe.h"
using namespace std;




template<class S,class T>
class Graphe
{
protected:
	int prochaineClef;
public:
	PElement<Sommet<T>> *lSommets;
	PElement<Arete<S,T>> *lAretes;
	explicit Graphe();

/**
 * constructeur de copie obligatoire car la classe comporte une partie dynamique
 * */
//Graphe(const Graphe<S,T> & graphe);

/**
 * op¨¦rateur = obligatoire car la classe comporte une partie dynamique
 * */
const Graphe<S,T> & operator = (const Graphe<S,T> & graphe);

/**
 * destructeur obligatoire car la classe comporte une partie dynamique
 * */
~Graphe();

int nombreSommets() const;
int nombreAretes() const;


Sommet<T> * creeSommet(const T & info);

Arete<S,T> * creeArete( Sommet<T> * debut, Sommet<T> * fin, const S & info);

											
operator string() const;

Arete<S,T> * getAreteParSommets( const Sommet<T> * s1, const Sommet<T> * s2) const;

PElement< pair< Sommet<T> *, Arete<S,T>* > >  *adjacences(const Sommet<T> * sommet) const;	
};
template <class S, class T>
Graphe<S,T>::Graphe():prochaineClef(0),lAretes(NULL),lSommets(NULL){}


/*template<class S,class T>
Graphe<S,T>::Graphe(const Graphe<S,T> &g)
{
	throw Erreur("pas encore ¨¦crit : reste ¨¤ faire");
}*/

template <class S, class T>
const Graphe<S,T> & Graphe<S,T>::operator = (const Graphe<S,T> & g1)
{
	{
		int i,j,k;
		int nbsommet,nbarete;
		PElement<Arete<S,T>>::efface2(this->lAretes);
	    PElement<Sommet<T>>::efface2(this->lSommets);
		nbsommet=g1.nombreSommets();
		nbarete=g1.nombreAretes();
		Sommet<InfoSommetCarte> * a[6];
		PElement<Sommet<InfoSommetCarte>> *ss;
		for(k=0,ss=g1.lSommets;ss;ss=ss->s)
		{
			a[k]=this->creeSommet(InfoSommetCarte(ss->v->v));
			k++;
		}
		double cout1=0.0;
		if(nbsommet!=nbarete)
		{
			for (i = 0, k = 0; i < nbsommet; ++i)
			{
				for (j = i+1; j < nbsommet; ++j)
				{
					double d = OutilsCarteRecuitSimule::distance(a[i],a[j]);  
					this->creeArete( a[i], a[j], InfoAreteCarte(d));
				}
			}
		}
		else
		{
			for(i=0,k=0;i<nbarete-1;i++)
			{
				double dd = OutilsCarteRecuitSimule::distance(a[i],a[i+1]); 
				cout1=cout1+dd;
				this->creeArete( a[i], a[i+1], InfoAreteCarte(dd));
			}
			double dd = OutilsCarteRecuitSimule::distance(a[i],a[0]);
			cout1=cout1+dd;
			this->creeArete( a[i], a[0], InfoAreteCarte(dd));
		}

		prochaineClef=g1.prochaineClef;
	}
	
	return *this;
}


template <class S, class T>
Graphe<S,T>::~Graphe()
{
	PElement<Arete<S,T>>::efface2(this->lAretes);
	PElement<Sommet<T>>::efface2(this->lSommets);
}

template <class S, class T>
Sommet<T> * Graphe<S,T>::creeSommet( const T & info)
{
	Sommet<T> *sommetCree=new Sommet<T>(prochaineClef++,info);
	lSommets=new PElement<Sommet<T>>(sommetCree,lSommets);
	return sommetCree;
}

template <class S, class T>
Arete<S,T> * Graphe<S,T>::creeArete( Sommet<T> * debut, Sommet<T> * fin, const S & info)
{
// ici tester que les 2 sommets sont bien existants dans le graphe
//if (! PElement< Sommet<T> >::appartient(debut,lSommets) ) throw Erreur("d¨¦but d'ar¨ºte non d¨¦fini");
//if (! PElement< Sommet<T> >::appartient(fin,lSommets)) throw Erreur("fin d'ar¨ºte non d¨¦finie");

	Arete<S,T> * nouvelleArete = new Arete<S,T>( prochaineClef++, debut, fin,  info);

	lAretes = new PElement< Arete<S,T> >( nouvelleArete, lAretes);
	debut->degre++; fin->degre++;

	return nouvelleArete;

}

template <class S, class T>
int Graphe<S,T>::nombreSommets() const
{
	return PElement< Sommet<T> >::taille(lSommets);
}

template <class S, class T>
int Graphe<S,T>::nombreAretes() const
{
	return PElement< Arete<S,T> >::taille(lAretes);
}

template <class S, class T>
Graphe<S,T>::operator string() const
{
	ostringstream oss;
	oss << "Graphe( \n";
	oss << "prochaine clef = "<< this->prochaineClef << endl;
	oss <<"nombre de sommets = "<< this->nombreSommets()<<"\n";

	oss << PElement<Sommet<T> >::toString( lSommets, "", "\n", "");

	oss <<"nombre d'ar¨ºtes = " << this->nombreAretes()<<"\n";

	oss << PElement<Arete<S,T> >::toString( lAretes, "", "\n", "");

	oss <<")";
	return oss.str();
}

template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S,T> & gr)
{
	return os << (string)gr;
}

template <class S, class T>
Arete<S,T> * Graphe<S,T>::getAreteParSommets( const Sommet<T> * s1, const Sommet<T> * s2) const
{
	PElement<Arete<S,T> > * l;

	for ( l = this->lAretes; l; l = l->s)
		if ( l->v->estEgal(s1,s2))
		   return l->v;

	return NULL;
}

template <class S, class T>
PElement< pair< Sommet<T> *, Arete<S,T>* > >  *  Graphe<S,T>::adjacences(const Sommet<T> * sommet) const
{
const PElement< Arete<S,T> > * l;

PElement< pair< Sommet<T> *, Arete<S,T>* > > * r;				// pair< Sommet<T> *, Arete<S,T>* >

for ( l = lAretes, r = NULL; l; l = l->s)
	
	if ( sommet == l->v->debut)
		r = new PElement< pair< Sommet<T> *, Arete<S,T>* > >
		( new pair< Sommet<T> *, Arete<S,T>* >(l->v->fin,l->v),r);
	else
		if ( sommet == l->v->fin)
		   r = new PElement< pair< Sommet<T> *, Arete<S,T>* > >
		   ( new pair< Sommet<T> *, Arete<S,T>* >
			(l->v->debut,l->v),r);
return r;
}





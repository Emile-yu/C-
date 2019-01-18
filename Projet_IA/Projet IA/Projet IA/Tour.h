#ifndef TOUR_H_
#define TOUR_H_

#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
#include"Arete.h"
#include"GElement.h"
#include"Sommet.h"
#include"Graphe.h"
#include"InfoAreteCarte.h"
#include"InfoSommetCarte.h"
#include"OutilsCarteRecuitSimule.h"
#include"recuitSimule.h"
using namespace std;

class Tour
{
protected:
	vector<Sommet<InfoSommetCarte> *> _tour;
	double distance;
public:
	explicit Tour();

	const Tour &operator =(const Tour &t);

	const Sommet<InfoSommetCarte> & operator[](int i)const;
	

	Tour(vector<Sommet<InfoSommetCarte> *> tour);
	

	vector<Sommet<InfoSommetCarte> *> getTour();

	void Vider();

	Sommet<InfoSommetCarte> * getVille(int i);

	void setVille(int i,Sommet<InfoSommetCarte> * s);
	

	void AddVille( Sommet<InfoSommetCarte> * s);
	
	Sommet<InfoSommetCarte> & operator[](int i)
	{
		return *_tour[i];
	}

	void generer(Tour &t);

	void alea();

	
	void setDistance()
	{
		distance=0;
	}

	double getDistance() const;
	

	int getNombreVille() const ;


	void afficher() const;
	

	friend ostream & operator << (ostream & o, const Tour & t);
};
#endif
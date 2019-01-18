

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

class Chemin
{
private:
	Graphe<InfoAreteCarte,InfoSommetCarte> gr;

public:
	Chemin()
	{
		gr.lAretes=NULL;
		gr.lSommets=NULL;
	}
	

	Graphe<InfoAreteCarte,InfoSommetCarte>  getChemin() const
	{
		return gr;
	}


};
extern ostream & operator <<(ostream &o,const Chemin &c);

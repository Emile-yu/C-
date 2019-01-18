#pragma once

#include <fstream>
#include <string>

#include "Graphe.h"
#include "InfoSommetCarte.h"
#include "InfoAreteCarte.h"

using namespace std;

class DessinGrapheRecuitSimule
{
public:

static void ecritSommets(ofstream & of, const Graphe<InfoAreteCarte, InfoSommetCarte> & graphe, const double & rayonSommet, const string & couleur)
{
	PElement<Sommet<InfoSommetCarte>> * l;

    for ( l = graphe.lSommets; l; l = l->s)
	{
		InfoSommetCarte * info = &(l->v->v);
		of << "point remarquable = "<< rayonSommet<< " "<<couleur<<" "<< info->position<<" " <<info->nom << info->position << endl;
	}

}

static void ecritAretes(ofstream & of, const Graphe<InfoAreteCarte, InfoSommetCarte> & graphe, const string & couleur)
{
	PElement<Arete<InfoAreteCarte,InfoSommetCarte>> * l;
    for ( l = graphe.lAretes; l; l = l->s)
	{
	of << "couleur =  " << couleur<<endl;
	of << "nombre de points = 2" << endl;
	of << l->v->debut->v.position << endl;
	of << l->v->fin->v.position << endl;
	}

}



static void ecritGraphe(ofstream & of, Graphe<InfoAreteCarte,InfoSommetCarte> & graphe, 
						const Vecteur2D & coinBG, const Vecteur2D & coinHD,
						const string & couleurRepere,
						const double & rayonSommet,
						const string & couleurSommets,
						const string & couleurAretes)
{
	string resume;

	resume = "carte routi¨¨re";

	DessinGraphe::ecrireEntete( of,  "carte routi¨¨re",  "carte routi¨¨re simplifi¨¦e repr¨¦sent¨¦e par un graphe", resume,  coinBG,  coinHD);

	DessinGraphe::ecritNombrePointsRemarquables( of, 3+graphe.nombreSommets());
	DessinGraphe::ecritRepere( of, couleurRepere);
	ecritSommets( of,  graphe, rayonSommet, couleurSommets);

	DessinGraphe::ecritNombreCourbes( of, graphe.nombreAretes());
	ecritAretes( of,  graphe, couleurAretes);

}
};

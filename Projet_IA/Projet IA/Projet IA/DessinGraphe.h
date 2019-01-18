#pragma once
#include <fstream>
#include "Vecteur2D.h"
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include <string.h>

using namespace std;
/**

m¨¦thodes n¨¦cessaires pour ¨¦crire un graphe-carte routi¨¨re dans un fichier texte de dessin avec visualisation d'un chemin

On suppose toujours que of est d¨¦j¨¤ ouvert en ¨¦criture seule
*/
class DessinGraphe
{
public:
	 static void ecrireEntete(ofstream & of, const string & titre, const string & legende, const string & resume, const Vecteur2D & coinBG, const Vecteur2D & coinHD)
	{

		of << "titre = " << titre << endl;
		of << "legende = " << legende << endl;
		of << "resume = " << resume << endl;
		of << "type de scene = courbes" << endl;
		of << "coin bas gauche de la figure sur l'¨¦cran en coordonn¨¦es monde = " << coinBG << endl;
		of << "coin haut droit de la figure sur l'¨¦cran en coordonn¨¦es monde = " << coinHD << endl; 
	}

	static void ecritNombrePointsRemarquables(ofstream & of, int nombrePoints)
	{
		of << "nombre de points remarquables = " << nombrePoints << endl;
	}


	static void ecritRepere(ofstream & of, const string & couleur)
	{
		of << "point remarquable = 2 black (0,0) O" << endl;
		of << "point remarquable = 2 black (1,0) 1" << endl;
		of << "point remarquable = 2 black (0,1) 1" << endl;
	}


	static void ecritNombreCourbes(ofstream & of, int nombreCourbes)
	{
		of << "nombre de courbes = "<< nombreCourbes << endl;
	}
};

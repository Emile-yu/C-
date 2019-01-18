#pragma once
#include<iostream>
#include<algorithm>
#include<time.h>
#include"Arete.h"
#include"GElement.h"
#include"Sommet.h"
#include"Graphe.h"
#include"InfoAreteCarte.h"
#include"InfoSommetCarte.h"
#include"OutilsCarteRecuitSimule.h"
#include"recuitSimule.h"
#include"Tour.h"
#include<math.h>
#include"DessinGraphe.h"
#include"DessinGrapheRecuitSimule.h"
#include"Chemin.h"
#include"recuitSimule.h"
using namespace std;

#define S1 6
#define A1 (S1*(S1-1)/2)
#define D1 6
 

double cout3(const Tour &g )
{
	return g.getDistance();
}
Tour changementAleatoire1( Tour &t)
{
	t.generer(t);
	return t;
}
double succ(const double &temperature)
{
	return temperature-1;
}
void main()
{
	Graphe<InfoAreteCarte,InfoSommetCarte> g1;

	Sommet<InfoSommetCarte> * s[S1];

	s[0] = g1.creeSommet(InfoSommetCarte("s0",Vecteur2D(1,2)));
	s[1] = g1.creeSommet(InfoSommetCarte("s1",Vecteur2D(3,1)));
	s[2] = g1.creeSommet(InfoSommetCarte("s2",Vecteur2D(5,2)));
	s[3] = g1.creeSommet(InfoSommetCarte("s3",Vecteur2D(5,3)));
	s[4] = g1.creeSommet(InfoSommetCarte("s4",Vecteur2D(3,4)));
	s[5] = g1.creeSommet(InfoSommetCarte("s5",Vecteur2D(1,3)));	

	Arete<InfoAreteCarte,InfoSommetCarte> * a[A1];

	int i,j;	
	int k;		

	for (i = 0, k = 0; i < S1; ++i)
	{
		for (j = i+1; j < S1; ++j)
		{
			double d = OutilsCarteRecuitSimule::distance(s[i],s[j]);  
			a[k++] = g1.creeArete( s[i], s[j], InfoAreteCarte(d));
		}
	}
	Graphe<InfoAreteCarte,InfoSommetCarte> g2;
	g2=g1;
	cout<<g2<<endl;

	/*Tour t;
	t.AddVille(s[0]);
	t.AddVille(s[1]);
	t.AddVille(s[2]);
	t.AddVille(s[3]);
	t.AddVille(s[4]);
	t.AddVille(s[5]);
	//t.alea();
	t.generer(t);
	
	
	Tour t1=recuitSimule(100.0,1.0,50,25,t,cout3,changementAleatoire1,succ);
    cout<<t1<<endl;
    //cout<<f.getDistance()<<endl;


	Graphe<InfoAreteCarte,InfoSommetCarte> g2;
	for(i=0;i<S1;i++)
	{
		g2.creeSommet(InfoSommetCarte(t1.getVille(i)->v));
	}
    

	Arete<InfoAreteCarte,InfoSommetCarte> * d1[D1];

	for(i=0,k=0;i<S1-1;i++)
	{
		double d2 = OutilsCarteRecuitSimule::distance(s[i],s[i+1]); 
		d1[k++] = g2.creeArete( s[i], s[i+1], InfoAreteCarte(d2));
	}
	double d2 = OutilsCarteRecuitSimule::distance(s[i],s[0]);
	d1[S1-1] = g2.creeArete( s[i], s[0], InfoAreteCarte(d2));

	cout<<g2<<endl;
	
 // PElement< pair< Sommet<InfoSommetCarte> *, Arete<InfoAreteCarte,InfoSommetCarte>* > >  v= *
   //cout<< *g1.adjacences(s[1])->v->first<<endl;
  //cout<< *g1.adjacences(s[1])->v->second<<endl;
   
	
    string nomFichierDessin = "grapheHexagonalComplet.txt";
	ofstream f(nomFichierDessin);							
	Vecteur2D coinBG(-1,-1), coinHD(5,5);					
	string couleurRepere = "blue";
	int rayonSommet = 5;									
	string couleurSommets = "red";
	string couleurAretes = "blue";
	DessinGrapheRecuitSimule::ecritGraphe(f, g1, coinBG, coinHD, couleurRepere, rayonSommet, couleurSommets, couleurAretes);

   cout << "le fichier texte de  dessin " << nomFichierDessin << " a ижtиж crижиж"<< endl;
   
  system("pause");*/
}


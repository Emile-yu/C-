#include <iostream>
#include "PElement.h"
#include "GElement.h"
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "OutilsCarteRecuitSimule.h"

#define S1 6
#define A1 (S1*(S1-1)/2)
#define D1 6
bool comp(const int* a, const int* b) {
	return *a < *b;
}
void func(int& a) {
	cout<<a<<endl;
	cout<<&a<<endl;
}

void func1(int** a) {
	**a = **a + 1;
}

int main() {
	/*int n1 = 1;
	PElement<int>* l = new PElement<int>(&n1, NULL);
	cout<<l<<endl;
	int n2 = 0;
	l->insertionOrdonnee(&n2,l,comp);
	cout<<l<<endl;
	l->efface1(l);
	cout<<l<<endl;
	cout<<l->taille(l)<<endl;

	cout<<endl;
	

	Sommet<int>* s1 = new Sommet<int>(1,1);
	Sommet<int>* s2 = new Sommet<int>(2,2);
	Sommet<int>* s3 = new Sommet<int>(3,3);
	cout<<*s1<<endl;
	cout<<*s2<<endl;

	Arete<int,int>* a1 = new Arete<int,int>(0,s1,s2,0);
	cout<<*a1<<endl;

	bool flag = a1->estEgal(s1,s2);
	if(flag) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	*/

	/*Graphe<int,int>* g = new Graphe<int,int>;
	Sommet<int>* s[2];
	s[0] = g->creeSommet(1);
	s[1] = g->creeSommet(2);
	cout<<*s[0]<<endl;
	cout<<*g<<endl;
	*/
	int c = 1;
	int* b = &c;
	func1(&b);
	cout<<c<<endl;
	cout<<*b<<endl;


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
	//cout<<g2<<endl;
	return 1;
}

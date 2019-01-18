#include<iostream>
#include"Diplome.h"
#include"Etudiant.h"
using namespace std;
void main()
{
	Stage *s=new Stage();
	Option *o1=new Option("YU");
	Option *o2=new Option("Jian");
	Option *o3=new Option("Gen");
	Diplome *d=new Diplome("license",s);
	Etudiant &e1=d->inscrire("Paul",19,1);
	Etudiant &e2=d->inscrire("Michael",18,1);
	Etudiant &e3=d->inscrire("Joe",17,1);
	Etudiant &e4=d->inscrire("Claire",16,0);
	Etudiant &e5=d->inscrire("Peter",20,0);
    (*o1).ajouter(&e1);
	(*o1).ajouter(&e4);
	(*o2).ajouter(&e2);
	(*o3).ajouter(&e3);
	(*o3).ajouter(&e5);
	
	(*d).ajouter(*o1);
	(*d).ajouter(*o2);
	(*d).ajouter(*o3);
	int i,j;
	for(i=0;i<(*d).getnb();i++)
	{   
		cout<<"la N"<<i<<"etudiant"<<endl;
		cout<<*s<<endl;
		cout<<(*d)[i]<<endl;
		Option o=(*d)[i];
		for(j=0;j<o.getnb();j++)
			cout<<o[j]<<endl;
	}
	cout<<endl;
	system("pause");
}
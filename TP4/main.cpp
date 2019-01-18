#include<iostream>
#include"Chanson.h"
#include"Artiste.h"
#include"Langues.h"
#include"Concert.h"
using namespace std;
int main()
{
	cout<<Langues::Fr<<endl;
	//cout<<&Langues::init(langues)<<endl;
	Artiste *a1=new Artiste("Michael",Langues::Fr);
	Artiste *a2=new Artiste("Joe");
	Artiste *a3=new Artiste("Peter");
	Artiste *a4=new Artiste("Claire");
	Chanson *c1=new Chanson("Sky",29,Langues::Ch);
	Chanson *c2=new Chanson("Blue",30);
	Chanson *c3=new Chanson("Sea",31);
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	(*c1).addArtiste(a1);
	(*c1).addArtiste(a2);
	(*c2).addArtiste(a3);
	(*c3).addArtiste(a4);

	cout<<*c1<<endl;
	Concert *c=new Concert("Jay Zhou","66.6");
	(*c).addChanson(c1);
	(*c).addChanson(c2);
	(*c).addChanson(c3);
	(*c).supp(0);
	//cout<<(*c).getDuree()<<endl;
	cout<<*c<<endl;
	
	//(*c).getArtiste();
	//system("pause");
	return 1;
}

#include"Tour.h"

Tour::Tour():distance(0)
{
}

Tour::Tour(vector<Sommet<InfoSommetCarte> *> tour)
{
	for(int i=0;i<_tour.size();i++)
	{
		_tour[i]=tour[i];
	}
}
const Sommet<InfoSommetCarte> & Tour::operator[](int i)const
	{
		return *_tour[i];
	}

const Tour &Tour::operator =(const Tour &t)
{  
	
	_tour.resize(t._tour.size());
	for(unsigned int i=0;i<_tour.size();i++)
	{
		
		//_tour.push_back(t._tour[i]);
		_tour[i]=t._tour[i];
	}
    
    
	distance=t.distance;
	return *this;
}

void Tour::Vider()
{
	/*for(unsigned int i=0;i<_tour.size();i++)
	{
		delete _tour[i];
	}
	_tour.clear();*/
	_tour.erase(_tour.begin(),_tour.end());
}

vector<Sommet<InfoSommetCarte> *> Tour::getTour()
{
	return _tour;
}

Sommet<InfoSommetCarte> * Tour::getVille(int i)
{
	return _tour[i];
}

void Tour::setVille(int i,Sommet<InfoSommetCarte> * s)
{
	_tour[i]=s;
	distance=0;
}

void Tour::AddVille( Sommet<InfoSommetCarte> * s)
{
	_tour.push_back(s);
}

void Tour::alea()
{
	srand(time(NULL));
	random_shuffle(_tour.begin(),_tour.end());
}
void Tour::generer(Tour &t)
{
	srand(time(NULL));
	int tourPos1,tourPos2;
	tourPos1=rand()%(t.getNombreVille());
	tourPos2=rand()%(t.getNombreVille());
	//Sommet<InfoSommetCarte> *v1=t.getVille(tourPos1);
	//Sommet<InfoSommetCarte> *v2=t.getVille(tourPos2);
    //while(tourPos1!=tourPos2 && t.getVille(tourPos1+1)!=t.getVille(tourPos2) && t.getVille(tourPos2+1)!=t.getVille(tourPos1))
	//t.setVille(tourPos1,v2);
	//t.setVille(tourPos2,v1);
	int i,max,min,d;

	while(abs(tourPos1-tourPos2)<=1 ||abs(tourPos1-tourPos2)==t.getNombreVille()-1)
	{
		tourPos1=rand()%(t.getNombreVille());
	    tourPos2=rand()%(t.getNombreVille());
	}
	cout<<"tourPos1= "<<tourPos1<<endl;
    cout<<"tourPos2= "<<tourPos2<<endl;
	if(tourPos1>tourPos2)
	{
		max=tourPos1;
		min=tourPos2;
	}
	else
	{
		max=tourPos2;
		min=tourPos1;
	}
	for(i=min+1;i<=min+(max-min)/2;i++)
	{
		Sommet<InfoSommetCarte> *v1=t.getVille(i);
	    Sommet<InfoSommetCarte> *v2=t.getVille(max+min-i+1);
		t.setVille(i,v2);
	    t.setVille(max+min-i+1,v1);
	}
	
}


double Tour::getDistance() const
{
	double d;
	int i,j,k;
	double m=0;
	for(i=0,k=0;i<_tour.size()-1;i++)
	{
		d = OutilsCarteRecuitSimule::distance(_tour[i],_tour[i+1]); 
		m=m+d;
	}
	d = OutilsCarteRecuitSimule::distance(_tour[i],_tour[0]);
	m=m+d;
	return m;
	
}

int Tour::getNombreVille() const
{
	return _tour.size();
}

void Tour::afficher() const
{
	for(unsigned int i=0;i<_tour.size();i++)
	{
		cout<<*(_tour[i])<<endl;
	}
}
ostream & operator << (ostream & o, const Tour & t)
{
	t.afficher();
	return o;
}
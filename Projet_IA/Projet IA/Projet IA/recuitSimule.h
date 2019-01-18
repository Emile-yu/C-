#pragma once
#include<stdlib.h>
#include"Tour.h"
#include"Vecteur2D.h"
#include"Graphe.h"
/*double tirageAleatoire(const double &a,const double &b)
{
	static int MAX=100,MAX1=99;
	double n=rand()%MAX;
	double m=n/MAX1;
	return a+m*(b-a);
}*/

template<class S>
const S recuitSimule(	const double &tInitiale
	                   ,const double &tFinale
					   ,const int &nbTentMax
					   ,const int &nbSuccMax
					   ,const S &solInit
					   ,double (*cout)(const S &solution)
					   ,S  (*changementAleatoire)( S & solution)
					   ,double (*succ)(const double &temperature)
					   
					   
			)

{
	
	double t;
	S s,sb,sp;
	t=tInitiale;
	s=solInit;
	sb=solInit;
	while( t>tFinale) 
	{
		int nbTent,nbSucc;
		nbTent=0;
		nbSucc=0;
		while(nbTent<nbTentMax && nbSucc<nbSuccMax)
		{
			nbTent=nbTent+1;
			sp=s;
			s=changementAleatoire(s);
			if(cout(s)<cout(sp))
			{
				nbSucc=nbSucc+1;
				if(cout(s)<cout(sb))
				{
					sb=s;
				}
			}
			else
			{
				double v,res;
				v=tirageAleatoire(0,1);
				res=cout(s)-cout(sp);
				if (v < exp(-res/t))
				{
					nbSucc=nbSucc+1;
				}
				else
				{
					s=sp;
				}
			}
		}
		if(nbSucc==0)
		{
			return sb;
		}
		t=succ(t);
	}
	return sb;
}
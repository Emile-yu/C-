#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include"Vecteur2D.h"
using namespace std;



const int maxnum = 200;
const int maxint = 999999;

 
void Solution(int n, int v,double *fi,double *fs ,double *dist,double *temp, int *prev, Vecteur2D **c)
{
    bool s[maxnum];    // Pour d¨¦terminer si le point a ¨¦t¨¦ d¨¦pos¨¦ dans la collection S
    for(int i=0; i<n; i++)
    {
        dist[i] = c[v][i].x;
		temp[i] = c[v][i].y;
        s[i] = 0;     // initialisation
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
 
    // Prenez minumum de dist[i] et Changer l'¨¦tat s[i]=1
    // Une fois que S contient tous les sommets dans V, 
	//dist sur la longueur de l'enregistrement du plus court chemin 
	//entre tous les autres sommets du point source au point puit
    for(int i=1; i<n; i++)
    {
        double tmp = maxint;
        int u = v;
        // Trouvez le point j est actuellement non utilis¨¦ qui avoir de minumum distance(dist [j]) 
        for(int j=0; j<n; j++)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              //u enregistrer le nombre actuel de voisins du point de distance minimale
                tmp = dist[j];
            }
        s[u] = 1;    // S u repr¨¦sente le point a ¨¦t¨¦ d¨¦pos¨¦ dans le tableau
 
        // Mise ¨¤ jour de tableau dist
        for(int j=0; j<n; j++)
            if((!s[j]) && c[u][j].x<maxint &&c[u][j].y<maxint)
            {
                double newdist = dist[u] + c[u][j].x;
				double newtemp = temp[u] + c[u][j].y;
				//on arrive apres l'heure
                if((newdist < dist[j]&& newtemp>fi[j] && newtemp<fs[j]) || (newdist == dist[j] && newtemp<temp[j] && newtemp>fi[j]) )
                {
                    dist[j] = newdist;
					temp[j] = newtemp;
					prev[j] = u;
                }
				//si on arrive avant l'heure
				if((newdist < dist[j]&& newtemp<fi[j] ) || newdist == dist[j] && newtemp<temp[j] && newtemp<fi[j] )
				{
					dist[j] = newdist;
					temp[j] = fi[j];
					prev[j] = u;
				}
	
            }
    }
	
}
 
void searchPath(string *b,int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout << b[que[i]] << " -> ";
        else
            cout << b[que[i]] << endl;
}
vector<string> Splite(string texte,string spliteSignal)
{
	vector<string> resultat;
    string strtemp;
	string::size_type pos1, pos2;
    pos2 = texte.find(spliteSignal);
    pos1 = 0;        
    while (pos2 != string::npos)
	{
		resultat.push_back(texte.substr(pos1, pos2 - pos1));
		pos1 = pos2 +spliteSignal.size();
		pos2 = texte.find(spliteSignal, pos1);
	}
	resultat.push_back(texte.substr(pos1));
	return resultat;
}

void main()
{
	ifstream infile("test3.txt", ios::in);
	string textline;
	getline(infile, textline);
	string delim(" ");
	string delim1("  ");
	vector<string> results=Splite(textline,delim);
	int num=std::atoi(results[4].c_str());//lire les donn¨¦es,nombre de sommet
	cout<<"              ******"<<"Instance de graphe "<<"******"<<endl;
	cout<<"Il y a "<< num <<" sommets"<<endl;
	cout<<endl;

	/************************/
	Vecteur2D **s1;
	s1=new Vecteur2D*[num];
	for(int i=0;i<num;i++)
	{
		s1[i]=new Vecteur2D[num];//initialiser le tableau de deux dimensions
	}
	Vecteur2D v(maxint,maxint);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			s1[i][j]=v;
		}
	}
	/************************/

	/************************/
	int nb;
	int j=0;
	string b[200];    //nom du chaque sommet
	double fi[200];   //borne inf¨¦rieur de la fen¨ºtre du chaque sommet
	double fs[200];   //borne sup¨¦rieur de la fen¨ºtre du chaque sommet
	getline(infile, textline);
	while(!infile.fail() && textline!="sectionSommets")
	{
		getline(infile, textline);
	}
	while(!infile.fail() && textline!="sources")
	{
		getline(infile, textline);
		if(textline!="\0" && textline!="sources")
		{
			vector<string> results=Splite(textline,delim1);
			b[j]=results[0].c_str();
			fi[j]=std::atoi(results[1].c_str());
	        fs[j]=std::atoi(results[2].c_str());
			j++;
		}
		
	}
	nb=j;
	
	while(!infile.fail() && textline!="sectionArcs")
	{
		getline(infile, textline);
	}
	while(!infile.fail() && textline!="sectionGraphes")
	{
		getline(infile, textline);
		//vector<string> strs=Splite(textline,delim);
		if(textline!="\0" && textline!="sectionGraphes")
		{
			//vector<string> strs;
			//split(textline,delim,strs);
			vector<string> strs=Splite(textline,delim1);
			for(int i=0;i<nb;i++)
			{
				for(int j=0;j<nb;j++)
				{
					if(b[i]==strs[1].c_str() && b[j]==strs[2].c_str())
					{
						s1[i][j].x=std::atoi(strs[3].c_str()); //stocker le cout dans le tableau de deux dimensions
					
						s1[i][j].y=std::atoi(strs[4].c_str()); //stocker le temps dans le tableau de deux dimensions
					}
				}
			}
		}
	}
	
	/************************/
	
	
	double dist[maxnum];     // Repr¨¦sente la plus courte cout du trajet du point source au point puit
	double temp[maxnum];     //Repr¨¦sente la plus courte temps du trajet du point source au point puit
    int prev[maxnum];     // enregistrer un noeud pr¨¦c¨¦de le noeud du point courant 
	
	
	for(int i=0; i<num; ++i)
        dist[i] = maxint;   //initialier
	for(int i=0; i<num; ++i)
        temp[i] = maxint;  //initialier

 
    Solution(num, 0,fi,fs, dist, temp,prev, s1);
 
   
    cout << "La plus courte COUT du trajet du point source au point puit: " << dist[num-1] << endl;
	cout << "La plus courte TEMPS du trajet du point source au point puit: " << temp[num-1] << endl;
 
    
    cout << "Le trajet que on le trouve: ";
    searchPath(b,prev, 0, num-1);
	
	
}
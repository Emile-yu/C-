#pragma once
#include<iostream>
#include<string>
using namespace std;
class Langues
{
private:
	static const char* _tab[4];
	Langues(){};
public:
	enum langues {Ch,Fr,Ang,All};

	static const char* init(enum langues lan){return _tab[lan];}
};
#pragma once
#include<iostream>
using namespace std;

class Langues
{
private:
	static const char* _tab[4];
public:
	enum langues {Ch,Fr,Ang,All};

	static const char* init(enum langues lan) {return _tab[lan];} 
};

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class GElement
{
public:
	int clef;

	GElement(const int clef);

    virtual operator string() const;

};
ostream & operator <<(ostream &o,const GElement &g);
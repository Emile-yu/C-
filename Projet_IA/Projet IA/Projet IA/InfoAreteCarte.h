#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class InfoAreteCarte
{
public:

double cout;

InfoAreteCarte( const double & cout):cout(cout){}

	
operator string() const;
};

ostream & operator << ( ostream & os, const InfoAreteCarte & infoAreteCarte);

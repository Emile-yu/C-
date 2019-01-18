#include <iostream>
#include <sstream>
#include "InfoAreteCarte.h"
using namespace std;


InfoAreteCarte::InfoAreteCarte(const double& _cout):cout(_cout){}

	
InfoAreteCarte::operator string() const {
	ostringstream oss;
	oss<<"cout :"<<this->cout<<endl;
	return oss.str();
}

	

ostream& operator<<(ostream& o, const InfoAreteCarte& i) {
	return o<<(string)i;
}
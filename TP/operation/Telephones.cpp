#include <iostream>
#include <string.h>
#include "Telephones.h"
using namespace std;

Telephones::Telephones(int type, char* tel) {
	m_iType = type;
	m_cTel = strdup(tel);
}
Telephones::Telephones(const Telephones& t) {
	m_iType = t.m_iType;
	m_cTel = strdup(t.m_cTel);
	cout<<"dup -- Tele"<<endl;
}

Telephones::~Telephones() {
	delete m_cTel;
	cout<<"Tel"<<endl;
}

ostream& operator<<(ostream& o, const Telephones& t) {
	o<<"Type:"<<t.getType()<<",Numero:"<<t.getNumero()<<endl;
	return o;
}

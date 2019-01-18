#ifndef TELEPHONES_H_
#define TELEPHONES_H_
#include <iostream>
using namespace std;
#define MOBILE 1
#define DOMICILE 2
#define BUREAU 3

class Telephones
{
public:
	Telephones(int type, char* tel);
	Telephones(const Telephones& t);
	~Telephones();
	char* getNumero() const {return m_cTel;}
	void setNumero(const char* tel) {
		delete m_cTel;
		m_cTel = strdup(tel);
	}
	int getType() const {return m_iType;}
	void setType(const int type) {
		m_iType = type;
	}

private:
	int m_iType;
	char* m_cTel; 	
};

extern ostream& operator<<(ostream& o, const Telephones& t);
#endif

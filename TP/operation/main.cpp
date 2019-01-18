#include <iostream>
#include <string.h>
#include "Telephones.h"
#include "Contacts.h"
using namespace std;

int main() {
	Telephones t1(MOBILE,"+33612345678");
	cout<<t1<<endl;

	Telephones t2(MOBILE,"33666666666");
	cout<<t2<<endl;

	Contacts c1("Jean","Dupont");
	cout<<c1<<endl;
	
	Contacts c2;
	c2 = c1 + t1;// + t1 +t2;
	
	cout<<c2.getNb()<<endl;
	cout<<c2<<endl;
	//cout<<"result:"<<c2[0].getNumero()<<endl;
	//cout<<"result:"<<c2[1].getNumero()<<endl;
	return 0;	

}

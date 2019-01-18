#include <iostream>
#include "strutil.h"
#include "String.h"
using namespace std;
using namespace pr;


int main() {
	String a = "abc";
	String b("efg");
	String c;
	if(a<b) cout<<"true"<<endl;
	c = a+b;

	cout<<c<<endl;
	return 0;
}
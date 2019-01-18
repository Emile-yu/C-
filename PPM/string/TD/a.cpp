#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char *a = "abc";
	char *b = new char[4];
	int ret =0;
	char *c=b;
	while((*b++ = *a++) != '\0') {ret++;};
	cout<<ret<<endl;
	b--;
	b--;
	cout<<*c<<endl;
	return 0;
}


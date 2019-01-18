#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main() {
	stringstream sstr; 
	//--------int转string----------- 
	int a=100; 
	string str; 
	sstr<<a; 
	sstr>>str; 
	cout<<str<<endl; 
	return 0;
} 

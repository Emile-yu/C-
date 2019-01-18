#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
	string line;
	int sum=0;
	while(getline(cin,line)) {
		int x;
		stringstream ss(line);
		while(ss >> x) sum+=x;
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}

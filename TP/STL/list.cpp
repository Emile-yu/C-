#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	list<int> l;
	l.push_back(1);
	l.push_back(1);
	l.push_back(3);
	l.push_back(4);
	l.insert(l.begin(),0);
	for(auto a:l) cout<<a<<endl;
	cout<<endl;
	
	list<int>::iterator it = remove(l.begin(),l.end(),1);
	cout<<*(l.end()) - *it<<endl;
	cout<<endl;
	
	l.erase(it,l.end());
	for(auto a:l) cout<<a<<endl;
	
	cout<<endl;
	list<int>::iterator it1 = lower_bound(l.begin(),l.end(),2);
	cout<<*it1<<endl;
	return 0;
}

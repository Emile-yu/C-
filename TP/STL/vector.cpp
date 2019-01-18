#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(v.begin(),0);
	for(auto a:v) cout<<a<<endl;
	cout<<endl;
	v.erase(remove(v.begin(),v.end(),1),v.end());
	
	for(auto a:v) cout<<a<<endl;
	
	cout<<endl;
	vector<int>::iterator it = lower_bound(v.begin(),v.end(),2);
	cout<<*it<<endl;
	return 0;
}

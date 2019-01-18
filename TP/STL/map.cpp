#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	map<int,int> m;
	m.insert(pair<int,int>(1,1));
	m.insert(make_pair(2,2));
	m[3] = 3;
	for(auto a:m) {
		cout<<a.first<<","<<a.second<<endl;
	}
	
	map<int,int>::iterator it = m.upper_bound(2);
	cout<<"position = "<<it->first<<endl;
	return 0;
}

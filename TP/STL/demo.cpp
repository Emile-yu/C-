#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main() {

	//allocation dynamique
	vector<int> *v;
	v=new vector<int>[10];
	v->push_back(1);
	cout<<v->front()<<endl;

	cout<<"STL::vector"<<endl;
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(6);
	
	//[] est déjà implémenté
	vector<int>::iterator it = vec.begin();
	for(;it!=vec.end();it++) {
		cout<<*it<<endl;
	}
	cout<<vec.front()<<endl;//first element
	cout<<vec.back()<<endl;//last element
	cout<<"---------"<<endl;
	
	cout<<"STL::list"<<endl;
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	//[] n'est pas implémenté, donc parcours par iterator
	list<int>::iterator it1 = l.begin();
	for(;it1!=l.end();it1++) {
		cout<<*it1<<endl;
	}
	cout<<"---------"<<endl;
	
	cout<<"STL::map"<<endl;
	map<int, string> m;
	pair<int, string> p1(1,"Hello");
	pair<int, string> p2(2,"World");
	m.insert(p1);
	m.insert(p2);
	
	map<int, string>::iterator it2 = m.begin();
	for(;it2!=m.end();it2++) {
		cout<<it2->first<<","<<it2->second<<endl;
	}
	
	cout<<"---------"<<endl;
	
	return 0;
}

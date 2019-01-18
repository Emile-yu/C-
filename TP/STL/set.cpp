#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {

	//set实现了红黑树的平衡二叉检索树的数据结构, 是有序的。
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(4);
	for(auto a:s) cout<<a<<endl;
	
	//unordered_set基于哈希表，是无序的。
	unordered_set<int> us;
	us.insert(3);
	us.insert(2);
	us.insert(1);
	us.insert(4);
	for(auto b:us) cout<<b<<endl;
	return 0;
}

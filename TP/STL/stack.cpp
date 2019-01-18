#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty()) {
		p=s.top();
		cout<<p<<endl;
		s.pop();
	}
	return 0;
}

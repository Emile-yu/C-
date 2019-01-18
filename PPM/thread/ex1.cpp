#include <iostream>
#include <thread>
using namespace std;
void func() {
	cout<<"thread"<<endl;
}

int main() {
	thread first(func);
	first.join();
	cout<<"finish"<<endl;
	return 0;
}

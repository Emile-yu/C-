#ifndef NODE_H_
#define NODE_H_
#include "Person.h"
#include <iostream>
using namespace std;
class Node
{
public:
	Person data;
	Node* next;
	Node() {cout<<"Node"<<endl;}
	~Node() {cout<<"~Node"<<endl;}
	void printNode();
};
#endif
#include <iostream>
#include "List.h"
#include "Node.h"
#include "Person.h"
using namespace std;

int menu() {
	cout<<"menu"<<endl;
	cout<<"1.create"<<endl;
	cout<<"2.delete"<<endl;
	cout<<"3.traverse"<<endl;
	cout<<"4.exit"<<endl;
	cout<<"Entre : ";
	int order=0;
	cin>>order;
	return order;
}

void createPerson(List* pList) {
	Node node;
	Person person;
	string name,phone;
	cout<<"name : ";
	cin>>name;
	cout<<"phone : ";
	cin>>phone;
	person.setName(name);
	person.setPhone(phone);
	node.data = person;
	pList->ListInsertTail(&node);
}

void deletePerson(List* pList) {
	Node node,temp;
	Person person;
	string name,phone;
	cout<<"name : ";
	cin>>name;
	cout<<"phone : ";
	cin>>phone;
	person.setName(name);
	person.setPhone(phone);
	node.data = person;
	int nb=pList->LocateElem(&node);
	pList->ListDelete(nb,&temp);
	
	
}

int main(int argc, char const *argv[])
{
	/*Node node1,node2,node3,node4,node5,node6;
	node1.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;
	node5.data = 0;
	List* pList = new List();

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	pList->ListInsert(1,&node5);
	pList->ListDelete(1,&node6);
	pList->ListTraverse();
	cout<<endl;
	cout<<"data:"<<node6.data<<endl;

	pList->NextElem(&node2,&node6);
	cout<<"data:"<<node6.data<<endl;
	delete pList;*/

	/*Node node1,node2,temp;
	Person p1("a","123");
	Person p2("b","234");

	node1.data = p1;
	node2.data = p2;
	List* pList = new List();
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListTraverse();
	pList->ListDelete(0,&temp);
	pList->ListTraverse();
	delete pList;
	*/
	
	int userOrder = 0;
	List* pList = new List();
	while(userOrder != 4) {
		userOrder = menu();
		switch(userOrder) {
			case 1:
				cout<<"Order->create"<<endl;
				createPerson(pList);
				break;
			case 2:
				cout<<"Order->delete"<<endl;
				deletePerson(pList);
				break;
			case 3:
				cout<<"Order->traverse"<<endl;
				pList->ListTraverse();
				break;
			case 4:
				cout<<"Order->exit"<<endl;
				break;
		}
	}

	delete pList;

	
	return 0;
}
#include <iostream>
#include "PElement.h"
using namespace std;


bool compar1(const int *a,const int *b)
{
    return *a <= *b;
}
int main() {
	int n = 2;
	PElement<int>* head = new PElement<int>(&n,NULL);
	int n1 = 4;
	int n2 = 1;
	int n3 = 3;
	head->insertionOrdonnee(&n1,head,compar1);
	head->insertionOrdonnee(&n2,head,compar1);
	head->insertionOrdonnee(&n3,head,compar1);
	cout<<head<<endl;
	head->efface1(head);
	cout<<head<<endl;
	delete head;
	return 1;
}

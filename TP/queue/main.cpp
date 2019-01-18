#include <iostream>
#include "MyQueue.h"
using namespace std;

int main(int argc, char const *argv[])
{
	/*MyQueue<int> * q = new MyQueue<int>(3);
	q->EnQueue(1);
	q->EnQueue(2);
	q->EnQueue(3);
	int elem;
	q->DeQueue(elem);
	q->DeQueue(elem);
	q->EnQueue(4);
	q->EnQueue(5);
	q->QueueTraverse();

	q->ClearQueue();
	q->QueueTraverse();
	cout<<endl;

	q->EnQueue(20);
	q->EnQueue(30);
	q->QueueTraverse();
	delete q;
	*/
	MyQueue<char> *q = new MyQueue<char>(3);
	q->EnQueue('a');
	q->EnQueue('b');
	q->EnQueue('c');
	q->QueueTraverse();
	return 0;
}
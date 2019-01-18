#include <iostream>
#include "Tree.h"
#define LEFT 0
#define RIGHT 1
using namespace std;
/*
数组与树之间的算法转换

int tree[n] 3 5 8 2 6 9 7		父节点下标*2+1为左节点
								父节点下标*2+2为右节点

			3(0)

	5(1)			8(2)

2(3)	6(4)	9(5)	7(6)

bool CreateTree(Tree** pTree, Node* pRoot);
void DestroyTree(Tree* pTree);
Node* SearchNode(Tree* pTree, int nodeIndex);
bool AddNode(Tree* pTree, int nodeIndex, int direction, Node* pNode);
bool DeleteNode(Tree* pTree, int nodeIndex, Node* pNode);
void TreeTraverse(Tree* pTree);	

*/

int main(int argc, char const *argv[])
{
	int root = 3;
	Tree* pTree = new Tree(10,&root);
	int node1 = 5;
	int node2 = 8;
	pTree->AddNode(0,LEFT,&node1);
	pTree->AddNode(0,RIGHT,&node2);

	int node3 = 2;
	int node4 = 6;
	pTree->AddNode(1,LEFT,&node3);
	pTree->AddNode(1,RIGHT,&node4);

	int node5 = 9;
	int node6 = 7;
	pTree->AddNode(2,LEFT,&node5);
	pTree->AddNode(2,RIGHT,&node6);

	int node =0;
	pTree->DeleteNode(6,&node);

	pTree->TreeTraverse();
	cout<<endl;
	int* p = pTree->SearchNode(2);
	cout<<"Search : "<<*p<<endl;


	delete pTree;
	return 0;
}
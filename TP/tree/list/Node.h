#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
	Node();
	Node* SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

	void BreadthFirstTraverse();
	void DepthFirstTraverse();
	int index;
	int data;
	Node* pLChild;
	Node* pRChild;
	Node* pParent;
	
};
#endif
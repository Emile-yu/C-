#include <iostream>
#include "Node.h"
#include <queue>
#include <stack>
using namespace std;
Node::Node() {
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node* Node::SearchNode(int nodeIndex) {
	if(nodeIndex == index) return this;
	Node* temp = NULL;
	if(this->pLChild != NULL) {
		if(this->pLChild->index == nodeIndex) {
			return this->pLChild;
		}else {
			temp = this->pLChild->SearchNode(nodeIndex);
			if(temp != NULL) {
				return temp;
			}
		}
	}
	if(this->pRChild != NULL) {
		if(this->pRChild->index == nodeIndex) {
			return this->pRChild;
		}else {
			temp = this->pRChild->SearchNode(nodeIndex);
			if(temp != NULL) {
				return temp;
			}
		}
	}
	return NULL;
}

void Node::DeleteNode() {
	if(this->pLChild != NULL) {
		this->pLChild->DeleteNode();
	}

	if(this->pRChild != NULL) {
		this->pRChild->DeleteNode();
	}

	if(this->pParent != NULL) {
		if(this->pParent->pLChild == this) {
			this->pParent->pLChild = NULL;
		}
		if(this->pParent->pRChild == this) {
			this->pParent->pRChild = NULL;
		}
	}

	delete this;
}

void Node::PreorderTraversal() {
	cout<<index<<":"<<data<<endl;
	if(this->pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}
	if(this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal() {
	
	if(this->pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}

	cout<<index<<":"<<data<<endl;

	if(this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
}
void Node::PostorderTraversal() {
	
	if(this->pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}
	if(this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
	cout<<index<<":"<<data<<endl;
}

void Node::BreadthFirstTraverse() {
	queue<Node*> q;
	q.push(this);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		cout<<temp->data<<endl;
		if(temp->pLChild != NULL) {
			q.push(temp->pLChild);
		}
		if(temp->pRChild != NULL) {
			q.push(temp->pRChild);
		}
	}
}

void Node::DepthFirstTraverse() {
	stack<Node*> s;
	s.push(this);
	while(!s.empty()) {
		Node* temp = s.top();
		s.pop();
		cout<<temp->data<<endl;
		if(temp->pRChild != NULL) {
			s.push(temp->pRChild);
		}
		if(temp->pLChild != NULL) {
			s.push(temp->pLChild);
		}
	}
}
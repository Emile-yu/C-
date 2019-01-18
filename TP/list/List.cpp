#include <iostream>
#include "List.h"
#include "Person.h"
using namespace std;

List::List() {
	//头节点为指引作用，下一个节点为第一个储存元素的节点
	m_pList = new Node();
	//m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

//删除第一个节点
List::~List() {
	ClearList();
	delete m_pList;
}

//删除除第一个节点外的所有节点
void List::ClearList() {
	Node* currentNode = m_pList->next;
	while(currentNode != NULL) {
		Node* temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
}

bool List::ListEmpty() {
	return m_iLength == 0?true:false;
}

int List::ListLength() {
	return m_iLength;
}

bool List::GetElem(int i, Node* pNode) {
	if(i < 0 || i >= m_iLength) {
		return false;
	}
	Node* temp = m_pList;
	while(i>=0) {
		temp = temp->next;
		i--;
	}
	pNode->data = temp->data;
	return false;

}

int List::LocateElem(Node* pNode) {
	int count = 0;
	Node* temp = m_pList;
	while(temp->next!=NULL) {
		temp = temp->next;
		if(temp->data == pNode->data) {
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PrioElem(Node* pCurrentNode, Node* pPreNode) {
	Node* temp = m_pList;
	Node* tempBefore = NULL;
	while(temp->next!=NULL) {
		tempBefore = temp;
		temp = temp->next;
		if(temp->data == pCurrentNode->data) {
			if(tempBefore == m_pList) {//前驱为头节点没有意义
				return false;
			}
			pPreNode->data = tempBefore->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node* pCurrentNode,Node* pNextNode) {
	Node* temp = m_pList;
	while(temp->next!=NULL) {
		temp = temp->next;
		if(temp->data == pCurrentNode->data) {
			if(temp->next == NULL) {
				return false;
			}
			pNextNode->data = temp->next->data;
			return true;
		}
	}
	return false;
}

void List::ListTraverse() {
	Node* currentNode = m_pList;
	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
		currentNode->printNode();
	}

}
bool List::ListInsert(int i, Node* pNode) {
	if(i < 0 || i > m_iLength) {
		return false;
	}
	Node* currentNode = m_pList;
	while(i > 0) {
		currentNode = currentNode->next;
		i--;
	}
	Node* newNode = new Node();
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

bool List::ListDelete(int i, Node* pNode) {
	if(i < 0 || i >= m_iLength) {
		return false;
	}
	Node* currentNode = m_pList;
	Node* currentNodeBefore = NULL;
	while(i >= 0) {
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
		i--;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	m_iLength--;
	return true;

}

bool List::ListInsertHead(Node* pNode) {
	Node* temp = m_pList->next;
	Node* newNode = new Node();
	if(newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node* pNode) {
	Node* currentNode = m_pList;
	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	Node* newNode = new Node();
	if(newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}
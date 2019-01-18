/*#include <iostream>
#include "MyQueue.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity) {
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[queueCapacity];
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

MyQueue::~MyQueue() {
	delete []m_pQueue;
}

void MyQueue::ClearQueue() {
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

bool MyQueue::QueueEmpty() {
	if(0 == m_iQueueLen) {
		return true;
	}
	return false;
}

bool MyQueue::QueueFull() {
	return m_iQueueLen == m_iQueueCapacity?true:false;
}

int MyQueue::QueueLength() {
	return m_iQueueLen;
}

bool MyQueue::EnQueue(int element) {
	if(QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = (m_iTail + 1)%m_iQueueCapacity; 
	m_iQueueLen++;
	return true;
}

bool MyQueue::DeQueue(int &element) {
	if(QueueEmpty()) {
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead = (m_iHead + 1)%m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

void MyQueue::QueueTraverse() {
	int nb = m_iQueueLen;
	while(nb > 0){
		cout<<m_pQueue[m_iHead]<<endl;
		m_iHead = (m_iHead+1)%m_iQueueCapacity;
		nb--;
	}
	
	for(int i =m_iHead;i<m_iQueueLen+m_iHead;i++) {
		cout<<m_pQueue[i%m_iQueueCapacity]<<endl;
	}
}
*/
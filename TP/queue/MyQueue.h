#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <iostream>
using namespace std;
/*环形队列*/
template <typename T>
class MyQueue
{
public:
	MyQueue(int queueCapacity);
	~MyQueue();
	void ClearQueue();
	bool QueueEmpty();
	bool QueueFull();
	int QueueLength();
	bool EnQueue(T element);
	bool DeQueue(T &element);
	void QueueTraverse();
private:
	T *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;
};
template <typename T>
MyQueue<T>::MyQueue(int queueCapacity) {
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new T[queueCapacity];
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

template <typename T>
MyQueue<T>::~MyQueue() {
	delete []m_pQueue;
}

template <typename T>
void MyQueue<T>::ClearQueue() {
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

template <typename T>
bool MyQueue<T>::QueueEmpty() {
	if(0 == m_iQueueLen) {
		return true;
	}
	return false;
}

template <typename T>
bool MyQueue<T>::QueueFull() {
	return m_iQueueLen == m_iQueueCapacity?true:false;
}

template <typename T>
int MyQueue<T>::QueueLength() {
	return m_iQueueLen;
}

template <typename T>
bool MyQueue<T>::EnQueue(T element) {
	if(QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iTail = (m_iTail + 1)%m_iQueueCapacity; 
	m_iQueueLen++;
	return true;
}

template <typename T>
bool MyQueue<T>::DeQueue(T &element) {
	if(QueueEmpty()) {
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead = (m_iHead + 1)%m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

template <typename T>
void MyQueue<T>::QueueTraverse() {
	/*int nb = m_iQueueLen;
	while(nb > 0){
		cout<<m_pQueue[m_iHead]<<endl;
		m_iHead = (m_iHead+1)%m_iQueueCapacity;
		nb--;
	}
	*/
	for(int i =m_iHead;i<m_iQueueLen+m_iHead;i++) {
		cout<<m_pQueue[i%m_iQueueCapacity]<<endl;
	}
}
#endif
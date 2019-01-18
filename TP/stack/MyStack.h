#ifndef MYSTACK_H_
#define MYSTACK_H_
#include <iostream>
using namespace std;
template <typename T>
class MyStack
{
public:
	MyStack(int size);//初始化栈空间
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse();
private:
	T* m_pBuffer;//栈空间
	int m_iSize;//栈容量
	int m_iTop;//栈顶，栈中元素
	
};

template <typename T>
MyStack<T>::MyStack(int size) {
	m_pBuffer = new T[size];
	m_iSize = size;
	m_iTop = 0;
}


template <typename T>
MyStack<T>::~MyStack() {
	delete []m_pBuffer;
	m_iSize = 0;
	m_iTop = 0;
}


template <typename T>
bool MyStack<T>::stackEmpty() {
	/*if (0 == m_iTop) {
		return true;
	}
	return false;*/
	return m_iTop == 0?true:false;
}


template <typename T>
bool MyStack<T>::stackFull() {
	/*if(m_iTop == m_iSize) {
		return true;
	}
	return false;
	*/
	return m_iTop == m_iSize?true:false;
}


template <typename T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}


template <typename T>
int MyStack<T>::stackLength() {
	return m_iTop;
}


template <typename T>
bool MyStack<T>::push(T elem) {
	if(!stackFull()) {
		m_pBuffer[m_iTop++] = elem;
		return true;
	}
	return false;
}


template <typename T>
bool MyStack<T>::pop(T &elem) {
	if(!stackEmpty()) {
		elem = m_pBuffer[--m_iTop];
		return true;
	}
	return false;
}


template <typename T>
void MyStack<T>::stackTraverse() {
	for(int i=0;i<m_iTop;i++) {
		cout<<m_pBuffer[i]<<endl;
	}
}
#endif

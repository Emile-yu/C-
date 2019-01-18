#include <iostream>
#include <string.h>
#include "CMap.h"
using namespace std;

CMap::CMap(int capacity) {
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[capacity];
	m_pMatrix = new int[capacity*capacity];
	memset(m_pMatrix,0,capacity*capacity);
	m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap() {
	delete []m_pNodeArray;
	delete []m_pMatrix;
	delete []m_pEdge;
}

bool CMap::addNode(Node* pNode) {
	if(m_iNodeCount == m_iCapacity) {
		return false;
	}
	m_pNodeArray[m_iNodeCount++].m_cData = pNode->m_cData;
	return true;
}

void CMap::resetNode() {
	for(int i=0;i<m_iNodeCount;i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val) {
	if((row < 0) || (row >=m_iCapacity)) return false;
	if((col < 0) || (col >=m_iCapacity)) return false;
	m_pMatrix[row*m_iCapacity+col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
	if((row < 0) || (row >=m_iCapacity)) return false;
	if((col < 0) || (col >=m_iCapacity)) return false;
	m_pMatrix[row*m_iCapacity+col] = val;
	m_pMatrix[col*m_iCapacity+row] = val;
	return true;
}

void CMap::printMatrix() {
	
	for(int i=0;i<m_iCapacity;i++) {
		char index = 'A';
		index=index+i;
		cout<<index<<":";
		for(int j=0;j<m_iCapacity;j++) {
			cout<<m_pMatrix[i*m_iCapacity+j];
		}
		cout<<endl;
	}
}

void CMap::depthFirstTraverse(int nodeIndex) {
	cout<<m_pNodeArray[nodeIndex].m_cData<<endl;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	int value;
	int i = nodeIndex;
	for(int j=i+1;j<m_iCapacity;j++) {
		getValueFromMatrix(i,j,value);
		if(value != 0) {
			if(m_pNodeArray[j].m_bIsVisited) {
				continue;
			}else {
				depthFirstTraverse(j);
			}
			
		}
	}
	
}

void CMap::breadthFirstTraverse(int nodeIndex) {
	cout<<m_pNodeArray[nodeIndex].m_cData<<endl;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector<int> v;
	v.push_back(nodeIndex);
	breadthFirstTraverseImpl(v);
	
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec) {
	int value;
	vector<int> v;
	for(int j=0;j<(int)preVec.size();j++) {
		for(int i=0;i<m_iCapacity;i++) {
			getValueFromMatrix(preVec[j],i,value);
			if(value != 0) {
				if(m_pNodeArray[i].m_bIsVisited) {
					continue;
				}else {
					cout<<m_pNodeArray[i].m_cData<<endl;
					m_pNodeArray[i].m_bIsVisited = true;
					v.push_back(i);
				}
			}
		}
	}
	if(v.size() == 0) return;
	else breadthFirstTraverseImpl(v);
}

bool CMap::getValueFromMatrix(int row, int col, int &val) {
	val = m_pMatrix[row*m_iCapacity+col];
	return true;
}

void CMap::primTree(int nodeIndex) {
	int value = 0;
	int edgeCount = 0;
	vector<int> nodeVec;
	vector<Edge> edgeVec;

	cout<<m_pNodeArray[nodeIndex].m_cData<<endl;
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	nodeVec.push_back(nodeIndex);

	while(edgeCount < m_iCapacity - 1) {
		int temp = nodeVec.back();
		int i;
		for(i=0;i<m_iCapacity;i++) {
			getValueFromMatrix(temp,i,value);
			if(value!=0) {
				if(m_pNodeArray[i].m_bIsVisited) continue;
				else {
					Edge edge(temp,i,value);
					edgeVec.push_back(edge);
				}
			}
		}
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;
		cout<<edgeVec[edgeIndex].m_iNodeIndexA<<"----->"<<edgeVec[edgeIndex].m_iNodeIndexB<<":";
		cout<<edgeVec[edgeIndex].m_iWeightValue<<endl;

		m_pEdge[edgeCount++] = edgeVec[edgeIndex];
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

		cout<<m_pNodeArray[nextNodeIndex].m_cData<<endl;
	}	
	
}

int CMap::getMinEdge(vector<Edge> edgeVec) {
	int minWeight = 0;
	int edgeIndex = 0;
	int i;

	for(i=0;i<edgeVec.size();i++) {
		if(!edgeVec[i].m_bSelected) {
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}
	if(minWeight == 0) return -1;
	for(;i<edgeVec.size();i++) {
		if(edgeVec[i].m_bSelected) continue;
		else {
			if(edgeVec[i].m_iWeightValue < minWeight) {
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}

	}

	return edgeIndex;
}
#include <iostream>
#include <string.h>
#include <algorithm>
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

/*

第二步






*/
void CMap::kruskalTree() {
	int value;
	int edgeCount=0;

	//定义存放节点集合的数组（多个集合组成一个完整的集合）
	vector< vector<int> > nodeSets;
	//第一步 取出所有的边
	vector<Edge> edgeVec;
	for(int i=0;i<m_iCapacity;i++) {
		for(int j=i+1;j<m_iCapacity;j++) {
			getValueFromMatrix(i,j,value);
			if(value != 0) {
				Edge edge(i,j,value);
				edgeVec.push_back(edge);
			}
		}
	}

	//1.找到算法结束条件
	while(edgeCount < m_iCapacity - 1) {

		//2.从边集合找到最小边
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		//3.找到最小边连接的点
		int nodeAIndex = edgeVec[edgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		
		int nodeAInSetLabel = -1;
		int nodeBInSetLabel = -1;
		//4.找到点所在的点集合
		bool nodeAIsInSet = false;
		bool nodeBIsInSet = false;
		for(int i=0;i<nodeSets.size();i++) {
			nodeAIsInSet = isInSet(nodeSets[i],nodeAIndex);
			if(nodeAIsInSet) {
				nodeAInSetLabel = i;
			}
		}

		for(int i=0;i<nodeSets.size();i++) {
			nodeAIsInSet = isInSet(nodeSets[i],nodeBIndex);
			if(nodeBIsInSet) {
				nodeBInSetLabel = i;
			}
		}


		//5.根据点所在的集合的不同作出不同处理
		if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1) {
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		}else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1) {
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
		}else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1) {
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		}else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel) {
			mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
			/*for(int k=nodeBInSetLabel;k<(int)nodeSets.size()-1;k++) {
				nodeSets[k] = nodeSets[k+1];
			}*/
			nodeSets.erase(
				remove(nodeSets.begin(),nodeSets.end(),nodeSets[nodeBInSetLabel]),nodeSets.end());
		}else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel) {
			continue;
		}

		m_pEdge[edgeCount++] = edgeVec[edgeIndex];

		cout<<edgeVec[edgeIndex].m_iNodeIndexA<<"-->"<<edgeVec[edgeIndex].m_iNodeIndexB<<":";
		cout<<edgeVec[edgeIndex].m_iWeightValue<<endl;
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

bool CMap::isInSet(vector<int> nodeSet, int target) {
	vector<int>::iterator it = find(nodeSet.begin(),nodeSet.end(),target);
	if(it != nodeSet.end()) return true;
	return false;	
	/*for(int i=0;i<nodeSet.size();i++) {
		if(nodeSet[i] == target) return true;
	}
	return false;*/
}
void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> &nodeSetB) {
	for(int i=0;i<nodeSetB.size();i++) {
		nodeSetA.push_back(nodeSetB[i]);
	}
}
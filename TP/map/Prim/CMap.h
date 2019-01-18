#ifndef CMAP_H_
#define CMAP_H_
#include <vector>
#include "Node.h"
#include "Edge.h"
using namespace std;
class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node* pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1);
	void printMatrix();
	void depthFirstTraverse(int nodeIndex);
	void breadthFirstTraverse(int nodeIndex);

	void primTree(int nodeIndex);
private:
	int m_iCapacity;
	int m_iNodeCount;
	Node* m_pNodeArray; //顶点数组
	int* m_pMatrix;     //邻接矩阵
	Edge* m_pEdge;
	
	bool getValueFromMatrix(int row, int col, int &val);
	void breadthFirstTraverseImpl(vector<int> preVec);
	int getMinEdge(vector<Edge> edgeVec);
};
#endif
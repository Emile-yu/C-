#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BreadthFirstSearch(TreeNode* root) {
	TreeNode* temp = root;
	queue<TreeNode*> q;
	q.push(temp);
	cout<<temp->val<<endl;
	while(!q.empty()) {
		TreeNode* top = q.front();
		q.pop();
		if(top->left) {
			cout<<top->left->val;
			q.push(top->left);
		}
		if(top->right) {
			cout<<top->right->val<<endl;
			q.push(top->right);
		}
	}
}

/*
		1
	   / \
	  2   3
	 / \ / \
	4  5 6  7 
*/

int main() {
	
	TreeNode head(1),node1(2),node2(3),node3(4),node4(5),node5(6),node6(7);
	head.left = &node1;
	head.right = &node2;
	
	
	node1.left = &node3;
	node1.right = &node4;
	
	node2.left = &node5;
	node2.right = &node6;
	
	BreadthFirstSearch(&head);
	return 0;
}

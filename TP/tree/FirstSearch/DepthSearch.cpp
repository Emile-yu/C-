#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DepthFirstSearch(TreeNode* root) {
	TreeNode* temp = root;
	stack<TreeNode*> s;
	s.push(temp);
	while(!s.empty()) {
		TreeNode* top = s.top();
		s.pop();
		cout<<top->val;
		if(top->right) {
			s.push(top->right);
		}
		if(top->left) {
			s.push(top->left);
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
	
	DepthFirstSearch(&head);
	return 0;
}

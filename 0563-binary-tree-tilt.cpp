#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int findTilt(TreeNode *root) {
		return root == nullptr ? 0 : abs(getSum(root->left) - getSum(root->right)) + findTilt(root->left) + findTilt(root->right);
	}

private:
	int getSum(TreeNode* root) {
		return root == nullptr ? 0 : root->val + getSum(root->left) + getSum(root->right);
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(3);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.findTilt(&node1) << endl;

	TreeNode node4 = TreeNode(3);
	TreeNode node5 = TreeNode(5);
	TreeNode node6 = TreeNode(7);
	node2 = TreeNode(2, &node4, &node5);
	node3 = TreeNode(9, nullptr, &node6);
	node1 = TreeNode(4, &node2, &node3);
	cout << solution.findTilt(&node1) << endl;
}

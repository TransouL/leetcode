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
	void dfs(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		dfs(node->left);
		dfs(node->right);
		if (node->left != nullptr && node->left->val == 0 && node->left->left == nullptr && node->left->right == nullptr) {
			node->left = nullptr;
		}
		if (node->right != nullptr && node->right->val == 0 && node->right->left == nullptr && node->right->right == nullptr) {
			node->right = nullptr;
		}
	}
public:
	TreeNode* pruneTree(TreeNode* root) {
		dfs(root);
		if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
			return nullptr;
		}
		return root;
	}
};

int main(void){
	Solution solution = Solution();

	TreeNode node1 = TreeNode(0);
	TreeNode node2 = TreeNode(1);
	TreeNode node3 = TreeNode(0, &node1, &node2);
	TreeNode node4 = TreeNode(1, nullptr, &node3);

	//TreeNode node1 = TreeNode(0);
	//TreeNode node2 = TreeNode(0);
	//TreeNode node3 = TreeNode(0, &node1, &node2);
	//TreeNode node4 = TreeNode(0, nullptr, &node3);

	cout << solution.pruneTree(&node4) << endl;
}

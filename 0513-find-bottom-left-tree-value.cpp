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
	int leafLevel = -1, bottomLeft;

	void dfs(int level, TreeNode* node) {
		if (node->left == nullptr && node->right == nullptr) {
			if (leafLevel < level) {
				leafLevel = level;
				bottomLeft = node->val;
			}
		}
		else {
			if (node->left != nullptr) {
				dfs(level + 1, node->left);
			}

			if (node->right != nullptr) {
				dfs(level + 1, node->right);
			}
		}
	}

public:
	int findBottomLeftValue(TreeNode* root) {
		dfs(0, root);
		return bottomLeft;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node4 = TreeNode(4);
	TreeNode node2 = TreeNode(2, &node4, nullptr);
	TreeNode node7 = TreeNode(7);
	TreeNode node5 = TreeNode(5, &node7, nullptr);
	TreeNode node6 = TreeNode(6);
	TreeNode node3 = TreeNode(3, &node5, &node6);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.findBottomLeftValue(&node1) << endl;
}

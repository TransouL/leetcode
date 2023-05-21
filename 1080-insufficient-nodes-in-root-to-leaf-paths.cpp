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
	bool checkSufficientLeaf(TreeNode *node, int sum, int limit) {
		if (!node) {
			return false;
		}
		if (node->left == nullptr && node->right == nullptr) {
			return node->val + sum >= limit;
		}
		bool hasSufficientLeft = checkSufficientLeaf(node->left, sum + node->val, limit);
		if (!hasSufficientLeft){
			node->left = nullptr;
		}
		bool hasSufficientRight = checkSufficientLeaf(node->right, sum + node->val, limit);
		if (!hasSufficientRight){
			node->right = nullptr;
		}
		return hasSufficientLeft || hasSufficientRight;
	}
public:
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		bool hasSuff = checkSufficientLeaf(root, 0, limit);
		return hasSuff ? root : nullptr;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node5 = TreeNode(-5);
	TreeNode node2 = TreeNode(2, &node5, nullptr);
	TreeNode node4 = TreeNode(4);
	TreeNode node3 = TreeNode(-3, &node4, nullptr);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.sufficientSubset(&node1, -1) << endl;
}

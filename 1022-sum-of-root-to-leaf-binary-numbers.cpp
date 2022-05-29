#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	int dfs(TreeNode* node, int curr) {
		if (node == nullptr) {
			return 0;
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				return (curr << 1) + node->val;
			}
			else {
				return dfs(node->left, (curr << 1) + node->val) + dfs(node->right, (curr << 1) + node->val);
			}
		}
	}
public:
	int sumRootToLeaf(TreeNode* root) {
		return dfs(root, 0);
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(0);
	TreeNode node2 = TreeNode(1);
	TreeNode node3 = TreeNode(0, &node1, &node2);
	TreeNode node4 = TreeNode(0);
	TreeNode node5 = TreeNode(1);
	TreeNode node6 = TreeNode(1, &node4, &node5);
	TreeNode node7 = TreeNode(1, &node3, &node6);
	cout << solution.sumRootToLeaf(&node7) << endl;
}

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
	int ans, deeplevel;
	void dfs(TreeNode *node, int level) {
		if (node == nullptr)
			return;
		if (level == deeplevel) {
			ans += node->val;
		}
		else if (level > deeplevel) {
			deeplevel = level;
			ans = node->val;
		}
		dfs(node->left, level + 1);
		dfs(node->right, level + 1);
	}

public:
	int deepestLeavesSum(TreeNode* root) {
		ans = deeplevel = 0;
		dfs(root, 0);
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node4 = TreeNode(4);
	TreeNode node5 = TreeNode(5);
	TreeNode node2 = TreeNode(2, &node4, &node5);
	TreeNode node6 = TreeNode(6);
	TreeNode node3 = TreeNode(3, nullptr, &node6);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.deepestLeavesSum(&node1) << endl;
}

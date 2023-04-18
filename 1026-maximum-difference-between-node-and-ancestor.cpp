#include <iostream>
#include <algorithm>

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
	int ans = 0;

	void dfs(TreeNode *node, int mn, int mx) {
		if (node == nullptr) {
			ans = max(ans, mx - mn);
			return;
		}
		mn = min(mn, node->val);
		mx = max(mx, node->val);
		dfs(node->left, mn, mx);
		dfs(node->right, mn, mx);
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		dfs(root, root->val, root->val);
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node3 = TreeNode(3);
	TreeNode node0 = TreeNode(0, &node3, nullptr);
	TreeNode node2 = TreeNode(2, nullptr, &node0);
	TreeNode node1 = TreeNode(1, nullptr, &node2);
	cout << solution.maxAncestorDiff(&node1) << endl;
}

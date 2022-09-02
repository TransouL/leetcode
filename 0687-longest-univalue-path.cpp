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
	int ans = 1;
	int dfs(TreeNode* node) {
		int res = 1;
		int l = 0, r = 0;
		if (node->left != nullptr) {
			l = dfs(node->left);
		}
		if (node->right != nullptr) {
			r = dfs(node->right);
		}

		if (l != 0 && node->val == node->left->val && r != 0 && node->val == node->right->val) {
			ans = max(ans, 1 + l + r);
			res += max(l, r);
		}
		else if (l != 0 && node->val == node->left->val) {
			res += l;
			ans = max(ans, res);
		}
		else if (r != 0 && node->val == node->right->val) {
			res += r;
			ans = max(ans, res);
		}

		return res;
	}
public:
	int longestUnivaluePath(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		dfs(root);
		return ans - 1;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(4);
	TreeNode node2 = TreeNode(4);
	TreeNode node3 = TreeNode(4, &node1, &node2);
	TreeNode node4 = TreeNode(5);
	TreeNode node5 = TreeNode(5, nullptr, &node4);
	TreeNode node6 = TreeNode(1, &node3, &node5);
	cout << solution.longestUnivaluePath(&node6) << endl;
}

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
	TreeNode* find(TreeNode* root, int x) {
		if (root->val == x) {
			return root;
		}
		TreeNode* ans = nullptr;
		if (root->left != nullptr) {
			ans = find(root->left, x);
		}
		if (ans == nullptr && root->right != nullptr) {
			ans = find(root->right, x);
		}
		return ans;
	}

	int dfs(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return 1 + dfs(node->left) + dfs(node->right);
	}
public:
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		TreeNode* node = find(root, x);
		if (root->val == x) {
			int left = dfs(root->left);
			return left != n - left - 1;
		}
		else {
			int p1left = dfs(node->left);
			int p1right = dfs(node->right);
			int p1father = n - 1 - p1left - p1right;
			int target = n / 2;
			return p1left > target || p1right > target || p1father > target;
		}
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node8 = TreeNode(8);
	TreeNode node9 = TreeNode(9);
	TreeNode node4 = TreeNode(4, &node8, &node9);
	TreeNode node10 = TreeNode(10);
	TreeNode node11 = TreeNode(11);
	TreeNode node5 = TreeNode(5, &node10, &node11);
	TreeNode node2 = TreeNode(2, &node4, &node5);
	TreeNode node6 = TreeNode(6);
	TreeNode node7 = TreeNode(7);
	TreeNode node3 = TreeNode(3, &node6, &node7);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.btreeGameWinningMove(&node1, 11, 3) << endl;
}

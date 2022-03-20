#include <iostream>
#include <unordered_set>

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
	int k;
	unordered_set<int> expects;
	bool dfs(TreeNode* node) {
		if (expects.count(node->val))
			return true;
		expects.emplace(k - node->val);
		if (node->left != nullptr && dfs(node->left))
			return true;
		if (node->right != nullptr && dfs(node->right))
			return true;
		return false;
	}

public:
	bool findTarget(TreeNode* root, int k) {
		TreeNode* maxNode = root;
		while (maxNode->right != nullptr)
			maxNode = maxNode->right;
		if (maxNode->val * 2 <= k)
			return false;

		this->k = k;
		return dfs(root);
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node2 = TreeNode(2);
	TreeNode node4 = TreeNode(4);
	TreeNode node3 = TreeNode(3, &node2, &node4);
	TreeNode node7 = TreeNode(7);
	TreeNode node6 = TreeNode(6, nullptr, &node7);
	TreeNode node5 = TreeNode(5, &node3, &node6);
	cout << solution.findTarget(&node5, 9) << endl;
	cout << solution.findTarget(&node5, 28) << endl;
}

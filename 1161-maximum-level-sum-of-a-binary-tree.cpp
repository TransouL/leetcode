#include <iostream>
#include <vector>
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
	void dfs(TreeNode* node, int level, vector<int> &levelSum) {
		if (node == nullptr)
			return;
		if (levelSum.size() == level) {
			levelSum.push_back(node->val);
		}
		else {
			levelSum[level] += node->val;
		}
		dfs(node->left, level + 1, levelSum);
		dfs(node->right, level + 1, levelSum);
	}

public:
	int maxLevelSum(TreeNode* root) {
		vector<int> levelSum;
		dfs(root, 0, levelSum);
		int maxLevel = levelSum[0], ans = 1;
		for (int i = 1; i < levelSum.size(); i++) {
			if (maxLevel < levelSum[i]) {
				ans = i + 1;
				maxLevel = levelSum[i];
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node5 = TreeNode(7);
	TreeNode node3 = TreeNode(-8);
	TreeNode node3_ = TreeNode(7, &node5, &node3);
	TreeNode node9 = TreeNode(0);
	TreeNode node1 = TreeNode(1, &node3_, &node9);
	cout << solution.maxLevelSum(&node1) << endl;
}

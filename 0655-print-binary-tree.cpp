#include <iostream>
#include <string>
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
	int height = 0;
	void getHeight(TreeNode* node, int level) {
		if (node == nullptr) {
			return;
		}
		if (height < level) {
			height = level;
		}
		getHeight(node->left, level + 1);
		getHeight(node->right, level + 1);
	}

	void dfs(TreeNode* node, vector<vector<string>> &ans, int row, int column) {
		if (node == nullptr) {
			return;
		}
		ans[row][column] = to_string(node->val);
		if (node->left != nullptr)
			dfs(node->left, ans, row + 1, column - (1 << height - row - 1));
		if (node->right != nullptr)
			dfs(node->right, ans, row + 1, column + (1 << height - row - 1));
	}
public:
	vector<vector<string>> printTree(TreeNode* root) {
		getHeight(root, 0);
		int n = (1 << (height + 1)) - 1;
		vector<vector<string>> ans(height + 1, vector<string>(n, ""));
		dfs(root, ans, 0, (n - 1) / 2);
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) {
		for (auto &e1 : e)
			cout << e1 << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	TreeNode node2 = TreeNode(2);
	TreeNode node1 = TreeNode(1, &node2, nullptr);
	printVector(solution.printTree(&node1));
	TreeNode node4 = TreeNode(4);
	node2 = TreeNode(2, nullptr, &node4);
	TreeNode node3 = TreeNode(3);
	node1 = TreeNode(1, &node2, &node3);
	printVector(solution.printTree(&node1));
}

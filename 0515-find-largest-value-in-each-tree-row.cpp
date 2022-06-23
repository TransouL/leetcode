#include <iostream>
#include <vector>
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
	void dfs(unsigned int level, TreeNode *node, vector<int> &largest) {
		if (node == nullptr) {
			return;
		}
		if (largest.size() > level) {
			largest[level] = max(largest[level], node->val);
		}
		else {
			largest.push_back(node->val);
		}
		dfs(level + 1, node->left, largest);
		dfs(level + 1, node->right, largest);
	}
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		dfs(0, root, ans);
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	TreeNode node5 = TreeNode(5);
	TreeNode node3 = TreeNode(3);
	TreeNode node3_ = TreeNode(3, &node5, &node3);
	TreeNode node9 = TreeNode(9);
	TreeNode node2 = TreeNode(2, nullptr, &node9);
	TreeNode node1 = TreeNode(1, &node3_, &node2);
	printVector(solution.largestValues(&node1));
}

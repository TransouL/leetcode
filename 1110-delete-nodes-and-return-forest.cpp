#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
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
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
		vector<TreeNode *> ans;

		function<bool(TreeNode *, bool)> dfs = [&](TreeNode *node, bool possible_root) -> bool {
			if (node == nullptr)
				return false;
			bool deleted = to_delete_set.count(node->val) ? true : false;
			if (dfs(node->left, deleted))
				node->left = nullptr;
			if (dfs(node->right, deleted))
				node->right = nullptr;
			if (deleted) {
				return true;
			}
			else {
				if (possible_root) {
					ans.emplace_back(node);
				}
				return false;
			}
		};

		dfs(root, true);
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
	TreeNode node4 = TreeNode(4);
	TreeNode node5 = TreeNode(5);
	TreeNode node6 = TreeNode(6);
	TreeNode node7 = TreeNode(7);
	TreeNode node2 = TreeNode(2, &node4, &node5);
	TreeNode node3 = TreeNode(3, &node6, &node7);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	printVector(solution.delNodes(&node1, vector<int>{3, 5}));
}

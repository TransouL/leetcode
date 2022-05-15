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
	void inorderTraversal(TreeNode* node, vector<TreeNode*> &ret) {
		if (node != nullptr) {
			inorderTraversal(node->left, ret);
			ret.push_back(node);
			inorderTraversal(node->right, ret);
		}
	}

public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (p->right != nullptr) {
			TreeNode *ans = p->right;
			while (ans->left != nullptr){
				ans = ans->left;
			}
			return ans;
		}

		vector<TreeNode*> nodes;
		inorderTraversal(root, nodes);
		vector<int> values;
		for (auto e : nodes) {
			values.push_back(e->val);
		}
		auto it = upper_bound(values.begin(), values.end(), p->val);
		if (it == values.end()) {
			return NULL;
		}
		else {
			return nodes[it - values.begin()];
		}
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(1);
	TreeNode node3 = TreeNode(3);
	TreeNode node2 = TreeNode(2, &node1, &node3);
	TreeNode *node = solution.inorderSuccessor(&node2, &node1);
	cout << node << endl;
}

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
	void dfs(TreeNode* curr, TreeNode* parent, bool isLeft, int val, int steps) {
		if (steps == 1) {
			TreeNode *newLeft = new TreeNode(val, curr->left, nullptr);
			TreeNode *newRight = new TreeNode(val, nullptr, curr->right);
			curr->left = newLeft;
			curr->right = newRight;
		}
		else {
			if (curr->left != nullptr) {
				dfs(curr->left, curr, true, val, steps - 1);
			}
			if (curr->right != nullptr) {
				dfs(curr->right, curr, false, val, steps - 1);
			}
		}
	}
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		if (depth == 1) {
			return new TreeNode(val, root, nullptr);
		}
		dfs(root, nullptr, false, val, depth - 1);
		return root;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(3);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.addOneRow(&node1, 4, 2) << endl;
}

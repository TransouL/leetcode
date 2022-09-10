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
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val < low) {
			return trimBST(root->right, low, high);
		}
		else if (root->val > high) {
			return trimBST(root->left, low, high);
		}
		else {
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(2, &node1, nullptr);
	TreeNode node3 = TreeNode(0, nullptr, &node2);
	TreeNode node4 = TreeNode(4);
	TreeNode node5 = TreeNode(3, &node3, &node4);
	cout << solution.trimBST(&node5, 1, 3) << endl;
}

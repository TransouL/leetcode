#include <iostream>
using namespace std;

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
	bool isUnivalTree(TreeNode* root) {
		if (root->left != nullptr && (!isUnivalTree(root->left) || root->val != root->left->val)) {
			return false;
		}
		if (root->right != nullptr && (!isUnivalTree(root->right) || root->val != root->right->val)) {
			return false;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(1);
	TreeNode node3 = TreeNode(1, &node1, &node2);
	cout << solution.isUnivalTree(&node3) << endl;
}

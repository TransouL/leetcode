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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		if (root->val > key)
			root->left = deleteNode(root->left, key);
		else if (root->val < key)
			root->right = deleteNode(root->right, key);
		else {
			if (!root->left)
				return root->right;
			if (!root->right)
				return root->left;
			TreeNode *successor = root->right;
			while (successor->left)
				successor = successor->left;
			successor->left = root->left;
			root = root->right;
		}
		return root;
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

	cout << solution.deleteNode(&node5, 3) << endl;
	cout << solution.deleteNode(&node5, 5) << endl;
}

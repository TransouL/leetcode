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
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		TreeNode *parent = nullptr, *curr = root;
		while (curr) {
			if (val > curr->val) {
				if (!parent) {
					return new TreeNode(val, root, nullptr);
				}
				TreeNode *node = new TreeNode(val, curr, nullptr);
				parent->right = node;
				return root;
			}
			else {
				parent = curr;
				curr = curr->right;
			}
		}
		parent->right = new TreeNode(val);
		return root;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node2 = TreeNode(2);
	TreeNode node1 = TreeNode(1);
	TreeNode node3 = TreeNode(3, &node2, nullptr);
	TreeNode node4 = TreeNode(4, &node1, &node3);
	cout << solution.insertIntoMaxTree(&node4, 5) << endl;
}

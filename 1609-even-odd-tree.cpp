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
public:
	bool isEvenOddTree(TreeNode* root) {
		vector<TreeNode*> evenLevel, oddLevel;
		bool isEvenLevel = true;
		evenLevel.emplace_back(root);
		while (true){
			if (isEvenLevel) {
				if (evenLevel.empty()) {
					break;
				}
				oddLevel.clear();
				int curr = 0;
				for (auto &node : evenLevel){
					int val = node->val;
					if (val & 1 && val > curr) {
						curr = val;
						if (node->left != nullptr){
							oddLevel.emplace_back(node->left);
						}
						if (node->right != nullptr){
							oddLevel.emplace_back(node->right);
						}
					}
					else {
						return false;
					}
				}
			}
			else {
				if (oddLevel.empty()) {
					break;
				}
				evenLevel.clear();
				int curr = 1000001;
				for (auto &node : oddLevel){
					int val = node->val;
					if (!(val & 1) && val < curr) {
						curr = val;
						if (node->left != nullptr){
							evenLevel.emplace_back(node->left);
						}
						if (node->right != nullptr){
							evenLevel.emplace_back(node->right);
						}
					}
					else {
						return false;
					}
				}
			}
			isEvenLevel = !isEvenLevel;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node12 = TreeNode(12);
	TreeNode node8 = TreeNode(8);
	TreeNode node6 = TreeNode(6);
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(3, &node12, &node8);
	TreeNode node7 = TreeNode(7, &node6, nullptr);
	TreeNode node9 = TreeNode(9, nullptr, &node2);
	TreeNode node10 = TreeNode(10, &node3, nullptr);
	TreeNode node4 = TreeNode(4, &node7, &node9);
	TreeNode node1 = TreeNode(1, &node10, &node4);
	cout << solution.isEvenOddTree(&node1) << endl;
}

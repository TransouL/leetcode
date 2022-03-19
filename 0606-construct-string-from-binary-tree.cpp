#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

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
	string tree2str(TreeNode* root) {
		string ans = "";
		if (root != nullptr) {
			stack<TreeNode *> st;
			st.push(root);
			unordered_set<TreeNode *> vis;
			while (!st.empty()) {
				TreeNode *node = st.top();
				if (vis.count(node)) {
					ans += ")";
					st.pop();
				}
				else {
					vis.insert(node);
					ans += "(";
					ans += to_string(node->val);
					TreeNode *left = node->left, *right = node->right;
					if (left == nullptr) {
						if (right != nullptr) {
							ans += "()";
							st.push(right);
						}
					}
					else {
						if (right != nullptr) {
							st.push(right);
						}
						st.push(left);
					}
				}
			}
		}
		return ans.substr(1, ans.size() - 2);
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node4 = TreeNode(4);
	TreeNode node2 = TreeNode(2, &node4, nullptr);
	TreeNode node3 = TreeNode(3);
	TreeNode node1 = TreeNode(1, &node2, &node3);
	cout << solution.tree2str(&node1) << endl;

	node4 = TreeNode(4);
	node2 = TreeNode(2, nullptr, &node4);
	node3 = TreeNode(3);
	node1 = TreeNode(1, &node2, &node3);
	cout << solution.tree2str(&node1) << endl;
}

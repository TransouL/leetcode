#include <iostream>
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
	void inorder(TreeNode* node, vector<int> &res) {
		if (node) {
			inorder(node->left, res);
			res.push_back(node->val);
			inorder(node->right, res);
		}
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> ans, res1, res2;
		inorder(root1, res1);
		inorder(root2, res2);
		auto idx1 = res1.begin();
		auto idx2 = res2.begin();
		while (idx1 < res1.end() || idx2 < res2.end()) {
			if (idx1 == res1.end()) {
				ans.insert(ans.end(), idx2, res2.end());
				break;
			}
			else if (idx2 == res2.end()) {
				ans.insert(ans.end(), idx1, res1.end());
				break;
			}
			else {
				int cand1 = *idx1, cand2 = *idx2;
				if (cand1 < cand2) {
					ans.push_back(*idx1++);
				}
				else if (cand1 > cand2) {
					ans.push_back(*idx2++);
				}
				else {
					ans.push_back(*idx1++);
					ans.push_back(*idx2++);
				}
			}
		}
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
	TreeNode node1 = TreeNode(1);
	TreeNode node4 = TreeNode(4);
	TreeNode node2 = TreeNode(2, &node1, &node4);
	TreeNode node0 = TreeNode(0);
	TreeNode node3 = TreeNode(3);
	TreeNode node1_ = TreeNode(1, &node0, &node3);
	printVector(solution.getAllElements(&node2, &node1_));
}

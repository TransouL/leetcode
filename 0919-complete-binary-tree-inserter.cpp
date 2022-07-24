#include <iostream>
#include <queue>
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

class CBTInserter {
private:
	queue<TreeNode *> q;
	TreeNode* root;

public:
	CBTInserter(TreeNode* root) {
		this->root = root;
		
		q.emplace(root);
		while (true) {
			bool done = false;
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				TreeNode* node = q.front();
				if (node->left == nullptr) {
					done = true;
					break;
				}
				else {
					q.emplace(node->left);
				}
				if (node->right == nullptr) {
					done = true;
					break;
				}
				else {
					q.emplace(node->right);
				}
				q.pop();
			}
			if (done) {
				break;
			}
		}
	}

	int insert(int val) {
		TreeNode* node = q.front();
		int res = node->val;
		if (node->left == nullptr) {
			node->left = new TreeNode(val, nullptr, nullptr);
			q.emplace(node->left);
		}
		else {
			node->right = new TreeNode(val, nullptr, nullptr);
			q.emplace(node->right);
			q.pop();
		}
		return res;
	}

	TreeNode* get_root() {
		return root;
	}
};

int main(void){
	TreeNode node2 = TreeNode(2);
	TreeNode node1 = TreeNode(1, &node2, nullptr);
	CBTInserter cBTInserter = CBTInserter(&node1);
	cout << cBTInserter.insert(3) << endl;  // ·µ»Ø 1
	cout << cBTInserter.insert(4) << endl;  // ·µ»Ø 2
	cout << cBTInserter.get_root() << endl; // ·µ»Ø [1, 2, 3, 4]
}

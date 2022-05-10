#include <iostream>
#include <string>
#include <vector>
#include <stack>

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

class Codec {
	const char separator = ',';

	void postOrder(TreeNode *root, vector<int> & arr) {
		if (root == nullptr)
			return;
		postOrder(root->left, arr);
		postOrder(root->right, arr);
		arr.emplace_back(root->val);
	}

	vector<int> split(const string &str) {
		int pos = 0;
		int start = 0;
		vector<int> res;
		while (pos < str.size()) {
			while (pos < str.size() && str[pos] == separator) {
				pos++;
			}
			start = pos;
			while (pos < str.size() && str[pos] != separator) {
				pos++;
			}
			if (start < str.size()) {
				res.emplace_back(stoi(str.substr(start, pos-start)));
			}
		}
		return res;
	}

	TreeNode *construct(int lower, int upper, stack<int> &st) {
		if (st.size() == 0 || st.top() < lower || st.top() > upper) {
			return nullptr;
		}
		int val = st.top();
		st.pop();
		TreeNode *root = new TreeNode(val);
		root->right = construct(val, upper, st);
		root->left = construct(lower, val, st);
		return root;
	}

public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		vector<int> arr;
		postOrder(root, arr);
		if (arr.size() == 0) {
			return res;
		}
		for (auto &num : arr) {
			res.append(to_string(num) + separator);
		}
		res.pop_back();
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		if (data.size() == 0)
			return nullptr;
		vector<int> arr = split(data);
		stack<int> st;
		for (auto &num : arr) {
			st.emplace(num);
		}
		return construct(INT_MIN, INT_MAX, st);
	}
};

int main(void){
	Codec codec = Codec();
	TreeNode node1 = TreeNode(1);
	TreeNode node3 = TreeNode(3);
	TreeNode node2 = TreeNode(2, &node1, &node3);
	string tree = codec.serialize(&node2);
	cout << tree << endl;
	codec.deserialize(tree);
}

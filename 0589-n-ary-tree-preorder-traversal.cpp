#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;
	Node() {}
	Node(int _val) {
		val = _val;
	}
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
	vector<int> ans;
	void dfs(Node* root) {
		ans.emplace_back(root ->val);
		for (auto &nodep : root->children) {
			dfs(nodep);
		}
	}
public:
	vector<int> preorder(Node* root) {
		if (root != nullptr)
			dfs(root);
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
	Node node5 = Node(5);
	Node node6 = Node(6);
	Node node3 = Node(3, vector<Node*> {&node5, &node6});
	Node node2 = Node(2);
	Node node4 = Node(4);
	Node node1 = Node(1, vector<Node*> {&node3, &node2, &node4});
	printVector(solution.preorder(&node1));
}
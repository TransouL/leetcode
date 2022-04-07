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
public:
	vector<vector<int>> levelOrder(Node *root) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			vector<Node *> level;
			ans.emplace_back(vector<int> { root->val });
			level.emplace_back(root);
			while (!level.empty()) {
				vector<int> nextValue;
				vector<Node *> next;
				for (auto &nodeP : level) {
					for (auto &childP : nodeP->children) {
						next.emplace_back(childP);
						nextValue.emplace_back(childP->val);
					}
				}
				if (next.empty()) {
					break;
				}
				else {
					ans.emplace_back(nextValue);
					level = next;
				}
			}
		}
		return ans;
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
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
	printVector(solution.levelOrder(&node1));
}
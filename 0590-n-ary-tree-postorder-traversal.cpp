#include <iostream>
#include <vector>
#include <stack>

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
	vector<int> postorder(Node* root) {
		vector<int> ans;
		if (root != nullptr) {
			stack<Node *> st;
			st.emplace(root);
			while (!st.empty()) {
				Node * node = st.top();
				st.pop();
				ans.emplace_back(node->val);
				for (auto & child : node->children) {
					st.emplace(child);
				}
			}
			reverse(ans.begin(), ans.end());
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
	Node node5 = Node(5);
	Node node6 = Node(6);
	Node node3 = Node(3, vector<Node*> {&node5, &node6});
	Node node2 = Node(2);
	Node node4 = Node(4);
	Node node1 = Node(1, vector<Node*> {&node3, &node2, &node4});
	printVector(solution.postorder(&node1));
}
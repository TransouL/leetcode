#include <iostream>
#include <vector>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

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
	int maxDepth(Node* root) {
		if (root == nullptr)
			return 0;
		int maxChild = 0;
		for (Node *child : root->children){
			maxChild = max(maxChild, maxDepth(child));
		}
		return maxChild + 1;
	}
};

int main(void){
	Solution solution = Solution();
	Node node5 = Node(5);
	Node node6 = Node(6);
	Node node3 = Node(3, vector<Node*> {&node5, &node6});
	Node node2 = Node(2);
	Node node4 = Node(4);
	Node node1 = Node(1, vector<Node*> {&node3, &node2, &node4});
	cout << solution.maxDepth(&node1) << endl;
}
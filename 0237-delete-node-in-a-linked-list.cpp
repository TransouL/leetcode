#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	string toString() {
		return to_string(val) + (next != NULL ? " -> " + next->toString() : "");
	}
};

class Solution {
public:
	void deleteNode(ListNode *node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main(void){
	Solution solution = Solution();
	ListNode node1 = ListNode(4);
	ListNode node2 = ListNode(5);
	ListNode node3 = ListNode(1);
	ListNode node4 = ListNode(9);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	solution.deleteNode(&node2);
	cout << node1.toString() << endl;
}

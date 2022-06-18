#include <iostream>
#include <string>

using namespace std;

struct Node {
	int val;
	Node *next;
	Node() : val(0), next(nullptr) {}
	Node(int x) : val(x), next(nullptr) {}
	Node(int x, Node *next) : val(x), next(next) {}
	string toString(Node* head) {
		return to_string(val) + (next != nullptr && next != head ? " -> " + next->toString(head) : "");
	}
};

class Solution {
public:
	Node* insert(Node* head, int insertVal) {
 		Node* insertNode = new Node(insertVal);
		if (head == nullptr) {
			insertNode->next = insertNode;
			return insertNode;
		}

		if (head->next == head) {
			head->next = insertNode;
			insertNode->next = head;
		}
		else {
			if (head->val == insertVal) {
				insertNode->next = head->next;
				head->next = insertNode;
			}
			else if (head->val < insertVal) {
				Node *curr = head, *next = head->next, *max = head;
				while (next->val < insertVal && next != head) {
					next = next->next;
					curr = curr->next;
					if (max->val <= curr->val) {
						max = curr;
					}
				}
				if (next->val < insertVal && next == head) {
					insertNode->next = max->next;
					max->next = insertNode;
				}
				else {
					insertNode->next = next;
					curr->next = insertNode;
				}	
			}
			else {
				Node *curr = head, *next = head->next, *max = head;
				while (curr->val > insertVal && next != head) {
					next = next->next;
					curr = curr->next;
					if (max->val <= curr->val) {
						max = curr;
					}
				}
				if (curr->val > insertVal && next == head) {
					insertNode->next = max->next;
					max->next = insertNode;
				}
				else {
					while (next->val < insertVal) {
						next = next->next;
						curr = curr->next;
					}
					insertNode->next = next;
					curr->next = insertNode;
				}
			}
		}

		return head;
	}
};

int main(void){
	Node node3 = Node(3);
	Node node1 = Node(1, &node3);
	Node node5 = Node(5, &node1);
	node3.next = &node5;
	Solution solution = Solution();
	solution.insert(&node5, 4);
	cout << node5.toString(&node5) << endl;
}

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode *ans = list1, *curr = list1;
		for (int i = 0; i < a - 1; i++) {
			curr = curr->next;
		}
		ListNode *right = curr->next;

		curr->next = list2;
		curr = list2;
		while (curr->next != nullptr) {
			curr = curr->next;
		}

		for (int i = 0; i < b - a + 1; i++) {
			right = right->next;
		}
		curr->next = right;
		
		return ans;
	}
};

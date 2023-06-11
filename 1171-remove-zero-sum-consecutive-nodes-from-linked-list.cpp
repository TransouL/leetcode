#include <iostream>
#include <vector>
#include <unordered_map>
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
	ListNode* removeZeroSumSublists(ListNode *head) {
		int preCurr = 0;
		ListNode dummy(0, head);
		unordered_map<int, ListNode*> mp;
		vector<int> preList(1, 0);
		mp[0] = &dummy;
		ListNode *curr = head;
		while (curr != nullptr) {
			preCurr += curr->val;
			if (mp.count(preCurr)) {
				mp[preCurr]->next = curr->next;
				while (preList.back() != preCurr) {
					mp.erase(preList.back());
					preList.pop_back();
				}
			}
			else {
				mp[preCurr] = curr;
				preList.push_back(preCurr);
			}
			curr = curr->next;
		}
		return dummy.next;
	}
};

int main(void){
	//ListNode node5 = ListNode(-2);
	//ListNode node4 = ListNode(-3, &node5);
	//ListNode node3 = ListNode(3, &node4);
	//ListNode node2 = ListNode(2, &node3);
	//ListNode node1 = ListNode(1, &node2);
	//Solution solution = Solution();
	//cout << solution.removeZeroSumSublists(&node1) << endl;
	ListNode node5 = ListNode(1);
	ListNode node4 = ListNode(3, &node5);
	ListNode node3 = ListNode(-3, &node4);
	ListNode node2 = ListNode(2, &node3);
	ListNode node1 = ListNode(1, &node2);
	Solution solution = Solution();
	cout << solution.removeZeroSumSublists(&node1) << endl;
}

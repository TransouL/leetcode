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
	int numComponents(ListNode* head, vector<int>& nums) {
		unordered_map<int, int> idxs;
		int idx = 0;
		while (head != nullptr){
			idxs.emplace(head->val, idx++);
			head = head->next;
		}
		vector<bool> flags(idx, false);
		for (auto &num : nums) {
			flags[idxs[num]] = true;
		}
		
		int ans = 0;
		bool prev = false;
		for (auto f : flags) {
			if (f && !prev) {
				++ans;
				prev = true;
			} else if (!f && prev) {
				prev = false;
			}
		}
		return ans;
	}
};

int main(void){
	ListNode node4 = ListNode(4);
	ListNode node3 = ListNode(3, &node4);
	ListNode node2 = ListNode(2, &node3);
	ListNode node1 = ListNode(1, &node2);
	ListNode node0 = ListNode(0, &node1);
	Solution solution = Solution();
	cout << solution.numComponents(&node0, vector<int> {0, 3, 1, 4}) << endl;
}

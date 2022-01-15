#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	ListNode *head;

public:
	Solution(ListNode *head) {
		this->head = head;
	}

	int getRandom() {
		int i = 1, ans;
		for (auto node = head; node != nullptr; node = node->next) {
			if (rand() % i == 0)
				ans = node->val;
			++i;
		}
		return ans;
	}
};

int main(void){
	ListNode node3 = ListNode(3);
	ListNode node2 = ListNode(2, &node3);
	ListNode node1 = ListNode(1, &node2);
	Solution solution = Solution(&node1);
	for (size_t i = 0; i < 10; i++){
		cout << solution.getRandom() << endl;
	}
}

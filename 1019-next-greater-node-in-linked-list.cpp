#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		stack<pair<int, int>> st;
		for (auto cur = head; cur; cur = cur->next) {
			while (!st.empty() && st.top().first < cur->val) {
				ans[st.top().second] = cur->val;
				st.pop();
			}
			st.emplace(cur->val, ans.size());
			ans.push_back(0);
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	ListNode node5 = ListNode(5);
	ListNode node1 = ListNode(1, &node5);
	ListNode node2 = ListNode(2, &node1);
	Solution solution = Solution();
	printVector(solution.nextLargerNodes(&node2));
}

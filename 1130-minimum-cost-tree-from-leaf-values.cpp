#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int mctFromLeafValues(vector<int>& arr) {
		int ans = 0;
		stack<int> stk;
		for (auto &x : arr) {
			while (!stk.empty() && stk.top() <= x) {
				int t = stk.top();
				stk.pop();
				if (stk.empty() || stk.top() > x) {
					ans += t * x;
				}
				else {
					ans += stk.top() * t;
				}
			}
			stk.push(x);
		}
		while (stk.size() >= 2) {
			int t = stk.top();
			stk.pop();
			ans += t * stk.top();
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.mctFromLeafValues(vector<int> {6, 2, 4}) << endl;
	cout << solution.mctFromLeafValues(vector<int> {4, 11}) << endl;
}
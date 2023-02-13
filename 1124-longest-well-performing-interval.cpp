#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestWPI(vector<int>& hours) {
		int n = hours.size();
		vector<int> pre(n + 1, 0);
		for (int i = 0; i < n; i++) {
			if (hours[i] > 8) {
				pre[i + 1] = pre[i] + 1;
			}
			else {
				pre[i + 1] = pre[i] - 1;
			}
		}

		int ans = 0;
		for (int i = n; i >= 1; --i) {
			if (pre[i] > 0) {
				ans = i;
				break;
			}
		}

		for (int r = ans + 1; r <= n; r++) {
			for (int l = 1; l < r - ans; l++) {
				if (pre[r] - pre[l] > 0) {
					ans = r - l;
					break;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.longestWPI(vector<int> {9, 9, 6, 0, 6, 6, 9}) << endl;
	cout << solution.longestWPI(vector<int> {6, 6, 6}) << endl;
	cout << solution.longestWPI(vector<int> {6, 9, 9}) << endl;
}
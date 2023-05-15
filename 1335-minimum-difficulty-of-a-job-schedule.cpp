#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jd, int d) {
		int n = jd.size();
		if (n < d) return -1;

		vector<int> dp(n);
		for (int i = 0, mx = 0; i < n; i++) {
			mx = max(mx, jd[i]);
			dp[i] = mx;
		}
		for (int i = 1; i < d; i++) {
			stack<pair<int, int>> st;
			vector<int> ndp(n);
			for (int j = i; j < n; j++) {
				int mn = dp[j - 1];
				while (!st.empty() && jd[st.top().first] < jd[j]) {
					mn = min(mn, st.top().second);
					st.pop();
				}
				if (st.empty()) {
					ndp[j] = mn + jd[j];
				}
				else {
					ndp[j] = min(ndp[st.top().first], mn + jd[j]);
				}
				st.emplace(j, mn);
			}
			swap(dp, ndp);
		}
		return dp[n - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minDifficulty(vector<int>{6, 5, 4, 3, 2, 1}, 2) << endl;
	cout << solution.minDifficulty(vector<int>{9, 9, 9}, 4) << endl;
	cout << solution.minDifficulty(vector<int>{1, 1, 1}, 3) << endl;
	cout << solution.minDifficulty(vector<int>{7, 1, 7, 1, 7, 1}, 3) << endl;
	cout << solution.minDifficulty(vector<int>{11, 111, 22, 222, 33, 333, 44, 444}, 6) << endl;
}
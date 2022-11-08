#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		vector<vector<int>> dp(n, vector<int>(n, n));
		unordered_set<int> banned;
		for (auto &&mine : mines) {
			banned.emplace(mine[0] * n + mine[1]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < n; j++) {
				// left + up
				if (banned.count(i * n + j)) {
					cnt1 = 0;
				}
				else {
					++cnt1;
				}
				dp[i][j] = min(dp[i][j], cnt1);

				if (banned.count(j * n + i)) {
					cnt2 = 0;
				}
				else {
					++cnt2;
				}
				dp[j][i] = min(dp[j][i], cnt2);
			}
			// right + down
			cnt1 = 0;
			cnt2 = 0;
			for (int j = n - 1; j >= 0; --j) {
				if (banned.count(i * n + j)) {
					cnt1 = 0;
				}
				else {
					++cnt1;
				}
				dp[i][j] = min(dp[i][j], cnt1);

				if (banned.count(j * n + i)) {
					cnt2 = 0;
				}
				else {
					++cnt2;
				}
				dp[j][i] = min(dp[j][i], cnt2);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; --j) {
				ans = max(ans, dp[j][i]);
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.orderOfLargestPlusSign(5, vector<vector<int>>{ {4, 2}}) << endl;
	cout << solution.orderOfLargestPlusSign(1, vector<vector<int>>{ {0, 0}}) << endl;
}
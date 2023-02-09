#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

class Solution {
public:
	int dieSimulator(int n, vector<int>& rollMax) {
		vector<vector<ll>> dp(n + 1, vector<ll>(7));
		for (int j = 1; j < 7; j++) {
			dp[1][j] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < 7; j++) {
				ll cnt = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0LL);
				int idx = i - 1 - rollMax[j - 1];
				if (idx >= 1) {
					cnt = accumulate(dp[idx].begin(), dp[idx].end(), cnt, [&](ll init, ll e) {
						return init + MOD - e;
					});
					cnt += dp[idx][j];
				}
				else if (idx == 0) {
					cnt -= 1;
				}
				dp[i][j] = cnt % MOD;
			}
		}
		return accumulate(dp[n].begin(), dp[n].end(), 0LL) % MOD;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.dieSimulator(2, vector<int> {1, 1, 2, 2, 2, 3}) << endl;
	cout << solution.dieSimulator(2, vector<int> {1, 1, 1, 1, 1, 1}) << endl;
	cout << solution.dieSimulator(3, vector<int> {1, 1, 1, 2, 2, 3}) << endl;
}
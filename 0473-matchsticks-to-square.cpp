#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4 != 0) {
			return false;
		}
		int edge = sum / 4, n = matchsticks.size();
		vector<int> dp(1 << n, -1);
		dp[0] = 0;
		for (int s = 1; s < (1 << n); s++) {
			for (int k = 0; k < n; k++) {
				if ((s & (1 << k)) == 0) {
					continue;
				}
				int sPre = s ^ (1 << k);
				if (dp[sPre] >= 0 && dp[sPre] + matchsticks[k] <= edge) {
					dp[s] = dp[sPre] + matchsticks[k] == edge ? 0 : dp[sPre] + matchsticks[k];
					break;
				}
			}
		}
		return dp[(1 << n) - 1] == 0;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.makesquare(vector<int> {1, 1, 2, 2, 2}) << endl;
	cout << solution.makesquare(vector<int> {3, 3, 3, 3, 4}) << endl;
	cout << solution.makesquare(vector<int> {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3}) << endl;
}

#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
	int countPalindromicSubsequences(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i + len <= n; i++) {
				int j = i + len - 1;
				if (s[i] == s[j]) {
					int low = i + 1;
					int high = j - 1;
					while (low <= high && s[low] != s[i]) {
						++low;
					}
					while (high >= low && s[high] != s[j]) {
						--high;
					}
					if (low > high) {
						dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD;
					}
					else if (low == high) {
						dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD;
					}
					else {
						dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
					}
				}
				else {
					dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
				}
			}
		}

		return dp[0][n - 1];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countPalindromicSubsequences("bccb") << endl;
	cout << solution.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
	cout << solution.countPalindromicSubsequences("bddaabdbbccdcdcbbdbddccbaaccabbcacbadbdadbccddccdbdbdbdabdbddcccadddaaddbcbcbabdcaccaacabdbdaccbaacc") << endl; // 744991227
}

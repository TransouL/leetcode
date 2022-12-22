#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int gcd(int a, int b) {
		return b != 0 ? gcd(b, a % b) : a;
	}

	int popcount(int x) {
		int ans = 0;
		while (x){
			ans += x & 1;
			x >>= 1;
		}
		return ans;
	}

public:
	int maxScore(vector<int>& nums) {
		int m = nums.size();
		vector<int> dp(1 << m, 0);
		vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
		for (int i = 0; i < m - 1; i++) {
			for (int j = i + 1; j < m; j++) {
				gcd_tmp[i][j] = gcd(nums[i], nums[j]);
			}
		}
		int all = 1 << m;
		for (int s = 1; s < all; s++) {
			int t = popcount(s);
			if (t & 1) {
				continue;
			}
			for (int i = 0; i < m - 1; i++) {
				if ((s >> i) & 1) {
					for (int j = i + 1; j < m; j++) {
						if ((s >> j) & 1) {
							dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
						}
					}
				}
			}
		}
		return dp[all - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxScore(vector<int> {1, 2}) << endl;
	cout << solution.maxScore(vector<int> {3, 4, 6, 8}) << endl;
	cout << solution.maxScore(vector<int> {1, 2, 3, 4, 5, 6}) << endl;
}
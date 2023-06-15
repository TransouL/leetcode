#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int popcount(int x) {
		int ans = 0;
		while (x){
			ans += x & 1;
			x >>= 1;
		}
		return ans;
	}

public:
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		vector<int> dp(1 << n, INT_MAX);
		vector<int> need(1 << n, 0);
		for (auto &edge : relations) {
			need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
		}
		dp[0] = 0;
		for (int i = 1; i < (1 << n); i++) {
			need[i] = need[i & (i - 1)] | need[i & (-i)];
			if ((need[i] | i) != i) {
				continue;
			}
			int valid = i ^ need[i];
			if (popcount(valid) <= k) {
				dp[i] = min(dp[i], dp[i ^ valid] + 1);
			}
			else {
				for (int sub = valid; sub; sub=(sub -1) & valid) {
					if (popcount(sub) <= k) {
						dp[i] = min(dp[i], dp[i ^ sub] + 1);
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minNumberOfSemesters(4, vector<vector<int>>{{2, 1}, { 3, 1 }, { 1, 4 }}, 2) << endl;
	cout << solution.minNumberOfSemesters(5, vector<vector<int>>{{2, 1}, { 3, 1 }, { 4, 1 }, { 1, 5 }}, 2) << endl;
	cout << solution.minNumberOfSemesters(11, vector<vector<int>>{}, 2) << endl;
}
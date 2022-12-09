#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxHeight(vector<vector<int>>& cuboids) {
		int n = cuboids.size();
		for (auto &v : cuboids) {
			sort(v.begin(), v.end());
		}
		sort(cuboids.begin(), cuboids.end(), [](const vector<int> &a, const vector<int> &b) {
			return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
		});
		int ans = 0;
		vector<int> dp(n);
		for (int i = 0; i < n; i++) {
			dp[i] = cuboids[i][2];
			for (int j = 0; j < i; j++) {
				if (cuboids[i][0] >= cuboids[j][0] &&
					cuboids[i][1] >= cuboids[j][1] &&
					cuboids[i][2] >= cuboids[j][2]) {
					dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxHeight(vector<vector<int>> {{50, 45, 20}, { 95, 37, 53 }, { 45, 23, 12 }}) << endl;
	cout << solution.maxHeight(vector<vector<int>> {{38, 25, 45}, { 76, 35, 3 }}) << endl;
	cout << solution.maxHeight(vector<vector<int>> {{7, 11, 17}, { 7, 17, 11 }, { 11, 7, 17 }, { 11, 17, 7 }, { 17, 7, 11 }, { 17, 11, 7 }}) << endl;
}
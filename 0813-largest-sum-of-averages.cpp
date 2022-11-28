#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double largestSumOfAverages(vector<int>& nums, int k) {
		int n = nums.size();
		vector<double> prefix(n + 1);
		for (int i = 0; i < n; i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}
		vector<double> dp(n + 1);
		for (int i = 0; i <=n; i++) {
			dp[i] = prefix[i] / i;
		}
		for (int j = 2; j <= k; j++) {
			for (int i = n; i >= j; --i) {
				for (int x = j - 1; x < i; x++) {
					dp[i] = max(dp[i], dp[x] + (prefix[i] - prefix[x]) / (i - x));
				}
			}
		}
		return dp[n];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.largestSumOfAverages(vector<int>{9, 1, 2, 3, 9}, 3) << endl;
	cout << solution.largestSumOfAverages(vector<int>{1, 2, 3, 4, 5, 6, 7}, 4) << endl;
}
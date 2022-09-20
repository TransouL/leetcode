#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int n = nums.size();
		int all = accumulate(nums.begin(), nums.end(), 0);
		if (all % k) {
			return false;
		}
		int per = all / k;
		sort(nums.begin(), nums.end());
		if (nums.back() > per) {
			return false;
		}
		
		vector<bool> dp(1 << n, true);
		function<bool(int, int)> dfs = [&](int s, int p)->bool {
			if (s == 0) {
				return true;
			}
			if (!dp[s]) {
				return false;
			}
			for (int i = 0; i < n; i++) {
				if (nums[i] + p > per) {
					break;
				}
				if ((s >> i) & 1) {
					if (dfs(s ^ (1 << i), p + nums[i] == per ? 0 : p + nums[i])) {
						return true;
					}
				}
			}
			dp[s] = false;
			return false;
		};
		return dfs((1 << n) - 1, 0);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canPartitionKSubsets(vector<int> {4, 3, 2, 3, 5, 2, 1}, 4) << endl;
	cout << solution.canPartitionKSubsets(vector<int> {1, 2, 3, 4}, 3) << endl;
}
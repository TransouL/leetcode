#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), curr = 0, ans = 0;
		while (k > 0 && curr < n && nums[curr] < 0){
			nums[curr] = -nums[curr];
			curr += 1;
			--k;
		}
		for (auto &num : nums) ans += num;
		if (k > 0 && (k & 1) == 1){
			if (curr == 0)
				ans -= nums[curr] * 2;
			else if (curr == n)
				ans -= nums[n - 1] * 2;
			else
				ans -= min(nums[curr], nums[curr - 1]) * 2;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.largestSumAfterKNegations(vector<int> { 4, 2, 3 }, 1) << endl;
	cout << solution.largestSumAfterKNegations(vector<int> { 3, -1, 0, 2 }, 3) << endl;
	cout << solution.largestSumAfterKNegations(vector<int> { 2, -3, -1, 5, -4 }, 2) << endl;
	cout << solution.largestSumAfterKNegations(vector<int> { -4, -2, -3 }, 4) << endl;
}
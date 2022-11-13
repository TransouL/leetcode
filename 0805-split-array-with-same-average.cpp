#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
	bool splitArraySameAverage(vector<int>& nums) {
		int n = nums.size(), m = n / 2;
		if (n == 1) {
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		for (auto &x : nums) {
			x = x * n - sum;
		}

		unordered_set<int> left;
		for (int i = 1; i < (1 << m); i++) {
			int tot = 0;
			for (int j = 0; j < m; j++) {
				if (i & (1 << j)) {
					tot += nums[j];
				}
			}
			if (tot == 0) {
				return true;
			}
			left.emplace(tot);
		}

		int rsum = accumulate(nums.begin() + m, nums.end(), 0);
		for (int i = 1; i < (1 << (n - m)) - 1; i++) {
			int tot = 0;
			for (int j = m; j < n; j++) {
				if (i & (1 << (j - m))) {
					tot += nums[j];
				}
			}
			if (tot == 0 || left.count(-tot)) {
				return true;
			}
		}
		return false;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.splitArraySameAverage(vector<int> {1, 2, 3, 4, 5, 6, 7, 8}) << endl;
	cout << solution.splitArraySameAverage(vector<int> {3, 1}) << endl;
}
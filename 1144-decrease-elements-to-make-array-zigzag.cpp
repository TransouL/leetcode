#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int n = nums.size(), needEven = 0, needOdd = 0;
		if (n == 1) {
			return 0;
		}

		if (nums[0] >= nums[1]) {
			needEven += nums[0] - nums[1] + 1;
		}
		if (nums[n - 1] >= nums[n - 2]) {
			if (n & 1) {
				needEven += nums[n - 1] - nums[n - 2] + 1;
			}
			else {
				needOdd += nums[n - 1] - nums[n - 2] + 1;
			}
		}

		for (int i = 1; i < n - 1; ++i) {
			int target = min(nums[i - 1], nums[i + 1]) - 1;
			if (i & 1) {
				if (nums[i] > target) {
					needOdd += nums[i] - target;
				}
			}
			else {
				if (nums[i] > target) {
					needEven += nums[i] - target;
				}
			}
		}
		return min(needEven, needOdd);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.movesToMakeZigzag(vector<int> {1, 2, 3}) << endl;
	cout << solution.movesToMakeZigzag(vector<int> {9, 6, 1, 6, 2}) << endl;
	cout << solution.movesToMakeZigzag(vector<int> {2, 7, 10, 9, 8, 9}) << endl; // 4
	cout << solution.movesToMakeZigzag(vector<int> {9, 10, 7, 1, 7, 6, 5, 5}) << endl; // 7
}
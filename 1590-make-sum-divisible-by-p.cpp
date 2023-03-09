#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		int totalRemain = 0;
		for (auto & num : nums) {
			totalRemain = (totalRemain + num) % p;
		}
		if (totalRemain == 0) {
			return 0;
		}
		unordered_map<int, int> remainLastIdx;
		int currRemain = 0, ans = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			remainLastIdx[currRemain] = i;
			currRemain = (currRemain + nums[i]) % p;
			int targetRemain = (currRemain - totalRemain + p) % p;
			if (remainLastIdx.count(targetRemain) > 0) {
				ans = min(ans, i - remainLastIdx[targetRemain] + 1);
			}
		}
		return ans == nums.size() ? -1 : ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minSubarray(vector<int> {3, 1, 4, 2}, 6) << endl;
	cout << solution.minSubarray(vector<int> {6, 3, 5, 2}, 9) << endl;
	cout << solution.minSubarray(vector<int> {1, 2, 3}, 3) << endl;
	cout << solution.minSubarray(vector<int> {1, 2, 3}, 7) << endl;
	cout << solution.minSubarray(vector<int> {1000000000, 1000000000, 1000000000}, 3) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minMaxGame(vector<int>& nums) {
		while (nums.size() > 1) {
			int n = nums.size();
			vector<int> newNumes = vector<int>(n / 2, 0);
			for (int i = 0; i < n / 2; i++) {
				if (i & 1) {
					newNumes[i] = max(nums[2 * i], nums[2 * i + 1]);
				}
				else {
					newNumes[i] = min(nums[2 * i], nums[2 * i + 1]);
				}
			}
			nums = newNumes;
		}
		return nums[0];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minMaxGame(vector<int>{1, 3, 5, 2, 4, 8, 2, 2}) << endl;
	cout << solution.minMaxGame(vector<int>{3}) << endl;
}
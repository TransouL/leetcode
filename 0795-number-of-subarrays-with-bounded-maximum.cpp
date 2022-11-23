#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
		int ans = 0, last2 = -1, last1 = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= left && nums[i] <= right) {
				last1 = i;
			}
			else if (nums[i] > right) {
				last2 = i;
				last1 = -1;
			}
			if (last1 != -1) {
				ans += last1 - last2;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numSubarrayBoundedMax(vector<int>{2, 1, 4, 3}, 2, 3) << endl;
	cout << solution.numSubarrayBoundedMax(vector<int>{2, 9, 2, 5, 6}, 2, 8) << endl;
}
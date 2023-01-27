#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int waysToMakeFair(vector<int>& nums) {
		int odd1 = 0, even1 = 0, odd2 = 0, even2 = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				odd2 += nums[i];
			}
			else {
				even2 += nums[i];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				odd2 -= nums[i];
			}
			else {
				even2 -= nums[i];
			}
			if (odd1 + even2 == odd2 + even1) {
				++ans;
			}
			if (i & 1) {
				odd1 += nums[i];
			}
			else {
				even1 += nums[i];
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.waysToMakeFair(vector<int> {2, 1, 6, 4}) << endl;
	cout << solution.waysToMakeFair(vector<int> {1, 1, 1}) << endl;
	cout << solution.waysToMakeFair(vector<int> {1, 2, 3}) << endl;
}
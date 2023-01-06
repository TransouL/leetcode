#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		vector<int> left, right;
		int n = nums.size(), lsum = 0, rsum = 0, ans = n + 1;
		for (int i = 0; i < n; i++) {
			lsum += nums[i];
			if (lsum <= x) {
				left.push_back(lsum);
			}
			else {
				break;
			}
		}
		for (int i = n - 1; i >= 0 ; --i) {
			rsum += nums[i];
			if (rsum <= x) {
				right.push_back(rsum);
			}
			else {
				break;
			}
		}
		if (!left.empty() && left.back() == x) {
			ans = left.size();
		}
		if (!right.empty() && right.back() == x) {
			ans = min(ans, (int)right.size());
		}
		int r = right.size() - 1;
		for (int l = 0; l < left.size(); l++) {
			while (r >= 0 && left[l] + right[r] > x) {
				--r;
			}
			if (r < 0) {
				break;
			}
			if (left[l] + right[r] == x) {
				ans = min(ans, l + r + 2);
			}
		}
		return ans == n + 1 ? -1 : ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minOperations(vector<int>{1, 1, 4, 2, 3}, 5) << endl;
	cout << solution.minOperations(vector<int>{5, 6, 7, 8, 9}, 4) << endl;
	cout << solution.minOperations(vector<int>{3, 2, 20, 1, 1, 3}, 10) << endl;
}
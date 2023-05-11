#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxValueAfterReverse(vector<int>& nums) {
		int base = 0, d = 0, mx = INT_MIN, mn = INT_MAX, n = nums.size();
		for (int i = 1; i < n; i++) {
			int a = nums[i - 1], b = nums[i];
			base += abs(a - b);
			mx = max(mx, min(a, b));
			mn = min(mn, max(a, b));
			d = max(d, max(abs(nums[0] - b) - abs(a - b), // i=0
				abs(nums[n - 1] - a) - abs(a - b))); // j=n-1
		}
		return base + max(d, 2 * (mx - mn));
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxValueAfterReverse(vector<int>{2, 3, 1, 5, 4}) << endl;
	cout << solution.maxValueAfterReverse(vector<int>{2, 4, 9, 24, 2, 1, 10}) << endl;
}
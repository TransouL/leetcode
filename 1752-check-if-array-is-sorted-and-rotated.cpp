#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool check(vector<int>& nums) {
		int min_ = nums[0];
		bool rotated = false;
		for (int i = 1; i < nums.size(); i++) {
			if (rotated) {
				if (nums[i] < nums[i - 1] || nums[i] > min_) {
					return false;
				}
			}
			else {
				if (nums[i] < nums[i - 1]) {
					if (nums[i] > min_) {
						return false;
					}
					else {
						rotated = true;
					}
				}
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.check(vector<int>{3, 4, 5, 1, 2}) << endl;
	cout << solution.check(vector<int>{2, 1, 3, 4}) << endl;
	cout << solution.check(vector<int>{1, 2, 3}) << endl;
	cout << solution.check(vector<int>{1, 3, 2}) << endl;
}
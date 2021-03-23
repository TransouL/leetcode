#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) {
			return false;
		}

		stack<int> mono_stack;
		mono_stack.push(nums[n - 1]);
		int max_num_2 = INT_MIN;

		for (int i = n - 2; i >= 0; --i) {
			if (nums[i] < max_num_2) {
				return true;
			}
			while (!mono_stack.empty() && nums[i] > mono_stack.top()) {
				max_num_2 = mono_stack.top();
				mono_stack.pop();
			}

			if (nums[i] > max_num_2) {
				mono_stack.push(nums[i]);
			}
		}

		return false;
	}
};

int main() {
	Solution solutuion;
	vector<int> nums = { 1, 2, 3, 4 };
	cout << solutuion.find132pattern(nums) << endl;
	nums = {3, 1, 4, 2};
	cout << solutuion.find132pattern(nums) << endl;
	nums = {-1, 3, 2, 0};
	cout << solutuion.find132pattern(nums) << endl;
	return 0;
}

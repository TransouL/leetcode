#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		int left = 1, right = *max_element(nums.begin(), nums.end());
		int ans = 0;
		while (left <= right) {
			int y = (left + right) / 2;
			long long ops = 0;
			for (auto &x : nums) {
				ops += (x - 1) / y;
			}
			if (ops <= maxOperations) {
				ans = y;
				right = y - 1;
			}
			else {
				left = y + 1;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumSize(vector<int>{9}, 2) << endl;
	cout << solution.minimumSize(vector<int>{2, 4, 8, 2}, 4) << endl;
	cout << solution.minimumSize(vector<int>{7, 17}, 2) << endl;
}
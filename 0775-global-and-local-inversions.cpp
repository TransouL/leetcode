#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isIdealPermutation(vector<int>& nums) {
		int n = nums.size(), minSuff = nums[n - 1];
		for (int i = n - 3; i >= 0 ; --i) {
			if (nums[i] > minSuff) {
				return false;
			}
			minSuff = min(minSuff, nums[i + 1]);
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.isIdealPermutation(vector<int> {1, 0, 2}) << endl;
	cout << solution.isIdealPermutation(vector<int> {1, 2, 0}) << endl;
}
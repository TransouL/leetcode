#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool findSubarrays(vector<int>& nums) {
		int n = nums.size();
		unordered_set<int> sums;
		for (int i = 0; i < n - 1; i++) {
			int t = nums[i] + nums[i + 1];
			if (sums.count(t)) {
				return true;
			}
			sums.emplace(t);
		}
		return false;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.findSubarrays(vector<int>{4, 2, 4}) << endl;
	cout << solution.findSubarrays(vector<int>{1, 2, 3, 4, 5}) << endl;
	cout << solution.findSubarrays(vector<int>{0, 0, 0}) << endl;
}
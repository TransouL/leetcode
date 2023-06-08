#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int distinctAverages(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		unordered_set<int> cnt;
		for (int i = 0; i < n / 2; i++) {
			cnt.insert(nums[i] + nums[n - i - 1]);
		}
		return cnt.size();
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.distinctAverages(vector<int>{4, 1, 4, 0, 3, 5}) << endl;
	cout << solution.distinctAverages(vector<int>{1, 100}) << endl;
}
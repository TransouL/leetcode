#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int ans = 0, n = nums.size();
		for (int i = 0, j = 1; i < n; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			j = max(i + 1, j);
			while (j < n && nums[j] - nums[i] < k) {
				++j;
			}
			if (j < n && nums[j] - nums[i] == k) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findPairs(vector<int> {3, 1, 4, 1, 5}, 2) << endl;
	cout << solution.findPairs(vector<int> {1, 2, 3, 4, 5}, 1) << endl;
	cout << solution.findPairs(vector<int> {1, 3, 1, 5, 4}, 0) << endl;
}
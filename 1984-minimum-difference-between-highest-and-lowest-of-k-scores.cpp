#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
	int minimumDifference(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 1)
			return 0;
		sort(nums.begin(), nums.end());
		int ans = 100000;
		for (int i = k - 1; i < n; i++) {
			ans = min(ans, nums[i] - nums[i - k + 1]);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minimumDifference(vector<int>{ 90 }, 1) << endl;
	cout << solution.minimumDifference(vector<int>{ 9, 4, 1, 7 }, 2) << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int mid = nums[n / 2];
		int ans = 0;
		for (auto &num : nums) {
			ans += abs(num - mid);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minMoves2(vector<int> { 1, 2, 3 }) << endl;
	cout << solution.minMoves2(vector<int> { 1, 10, 2, 9 }) << endl;
}

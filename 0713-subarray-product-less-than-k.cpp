#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int n = nums.size(), l = 0, product = 1, ans = 0;
		for (int r = 0; r < n; r++) {
			product *= nums[r];
			while (l <= r && product >= k) {
				product /= nums[l++];
			}
			ans += r - l + 1; 
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numSubarrayProductLessThanK(vector<int> {10, 5, 2, 6}, 100) << endl;
	cout << solution.numSubarrayProductLessThanK(vector<int> {1, 2, 3}, 0) << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
	int sumSubseqWidths(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		long long ans = 0, pow = 1;
		for (int i = 0; i < n; i++, pow = (pow * 2) % MOD) {
			ans = (ans + pow * (nums[i] - nums[n - i - 1])) % MOD;
		}
		return (int)ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.sumSubseqWidths(vector<int> {2, 1, 3}) << endl;
	cout << solution.sumSubseqWidths(vector<int> {2}) << endl;
}
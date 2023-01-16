#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int MOD = 1000000007;

class Solution {
	int rev(int x) {
		int ans = 0;
		while (x) {
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return ans;
	}

public:
	int countNicePairs(vector<int>& nums) {
		unordered_map<long, long> stats;
		for (auto &num : nums) {
			++stats[num - rev(num)];
		}
		long ans = 0;
		for (auto &p : stats){
			ans = (ans + p.second * (p.second - 1) / 2) % MOD;
		}
		return (int)ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countNicePairs(vector<int> {42, 11, 1, 97}) << endl;
	cout << solution.countNicePairs(vector<int> {13, 10, 35, 24, 76}) << endl;
}
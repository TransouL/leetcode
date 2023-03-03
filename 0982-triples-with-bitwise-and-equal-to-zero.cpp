#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countTriplets(vector<int>& nums) {
		vector<int> cnt(1 << 16);
		for (auto &x : nums) {
			for (auto &y : nums) {
				++cnt[x & y];
			}
		}
		int ans = 0;
		for (auto &z : nums) {
			z = z ^ 0xFFFF;
			for (int sub = z; sub; sub = (sub - 1) & z) {
				ans += cnt[sub];
			}
			ans += cnt[0];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countTriplets(vector<int> {2, 1, 3}) << endl;
	cout << solution.countTriplets(vector<int> {0, 0, 0}) << endl;
}
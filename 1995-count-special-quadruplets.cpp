#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int countQuadruplets(vector<int>& nums) {
		size_t n = nums.size(), ans = 0;
		unordered_map<int, int> stats;
		for (size_t b = n - 3; b >= 1; --b) {
			for (size_t d = b + 2; d < n; ++d) {
				++stats[nums[d] - nums[b + 1]];
			}
			for (size_t a = 0; a < b; ++a) {
				int expectedVal = nums[a] + nums[b];
				if (stats.count(expectedVal))
					ans += stats[expectedVal];
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countQuadruplets(vector<int> { 1, 2, 3, 6 }) << endl;
	cout << solution.countQuadruplets(vector<int> { 3, 3, 6, 4, 5 }) << endl;
	cout << solution.countQuadruplets(vector<int> { 1, 1, 1, 3, 5 }) << endl;
}

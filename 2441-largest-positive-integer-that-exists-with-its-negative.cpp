#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int findMaxK(vector<int>& nums) {
		unordered_set<int> seen;
		int ans = -1;
		for (auto &num : nums) {
			if (abs(num) > ans) {
				if (seen.count(-num)) {
					ans = abs(num);
				}
				else {
					seen.emplace(num);
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.findMaxK(vector<int>{-1, 2, -3, 3}) << endl;
	cout << solution.findMaxK(vector<int>{-1, 10, 6, 7, -7, 1}) << endl;
	cout << solution.findMaxK(vector<int>{-10, 8, 6, 7, -2, -3}) << endl;
}
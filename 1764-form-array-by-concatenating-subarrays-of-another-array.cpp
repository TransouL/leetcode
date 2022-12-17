#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		int idx = 0, n = nums.size();
		for (auto &g : groups) {
			int gn = g.size();
			if (gn > n - idx) {
				return false;
			}
			bool found = false;
			for (int start = idx; start <= n - gn; start++) {
				bool notMatch = false;
				for (int i = 0; i < gn; i++) {
					if (nums[start + i] != g[i]) {
						notMatch = true;
						break;
					}
				}
				if (!notMatch) {
					found = true;
					idx = start + gn;
					break;
				}
			}
			if (!found) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.canChoose(vector<vector<int>> {{1, -1, -1}, { 3, -2, 0 }}, vector<int> {1, -1, 0, 1, -1, -1, 3, -2, 0}) << endl;
	cout << solution.canChoose(vector<vector<int>> {{10, -2}, { 1, 2, 3, 4 }}, vector<int> {1, 2, 3, 4, 10, -2}) << endl;
	cout << solution.canChoose(vector<vector<int>> {{1, 2, 3}, { 3, 4 }}, vector<int> {7, 7, 1, 2, 3, 4, 7, 7}) << endl;
}
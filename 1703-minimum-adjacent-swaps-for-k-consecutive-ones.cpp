#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums, int k) {
		vector<int> g, pre(1, 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				g.emplace_back(i - g.size());
				pre.emplace_back(pre.back() + g.back());
			}
		}
		int  m = g.size(), ans = INT_MAX;
		for (int i = 0; i <= m - k; i++) {
			int mid = i + k / 2;
			ans = min(ans, (1 - k % 2) * g[mid] + (pre[i + k] - pre[mid + 1]) - (pre[mid] - pre[i]));
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minMoves(vector<int> {1, 0, 0, 1, 0, 1}, 2) << endl;
	cout << solution.minMoves(vector<int> {1, 0, 0, 0, 0, 0, 1, 1}, 3) << endl;
	cout << solution.minMoves(vector<int> {1, 1, 0, 1}, 2) << endl;
}
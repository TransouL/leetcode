#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int unequalTriplets(vector<int>& nums) {
		unordered_map<int, int> stats;
		for (auto &num : nums) {
			++stats[num];
		}
		int n = stats.size();
		if (n < 3) {
			return 0;
		}
		vector<int> cnts;
		for (auto it = stats.begin(); it != stats.end(); ++it) {
			cnts.push_back(it->second);
		}
		int ans = 0;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					ans += cnts[i] * cnts[j] * cnts[k];
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.unequalTriplets(vector<int>{4, 4, 2, 4, 3}) << endl;
	cout << solution.unequalTriplets(vector<int>{1, 1, 1, 1, 1}) << endl;
}
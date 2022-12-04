#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		int x = *min_element(baseCosts.begin(), baseCosts.end());
		if (x >= target) {
			return x;
		}
		vector<bool> can(target + 1, false);
		int ans = 2 * target - x;
		for (auto &b : baseCosts) {
			if (b <= target) {
				can[b] = true;
			}
			else {
				ans = min(ans, b);
			}
		}
		for (auto &t : toppingCosts) {
			for (int count = 0; count < 2; count++) {
				for (int i = target; i > 0 ; --i) {
					if (can[i] && i + t > target) {
						ans = min(ans, i + t);
					}
					if (i - t > 0) {
						can[i] = can[i] | can[i - t];
					}
				}
			}
		}
		for (int i = 0; i <= ans - target; i++) {
			if (can[target - i]) {
				return target - i;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.closestCost(vector<int>{1, 7}, vector<int> {3, 4}, 10) << endl;
	cout << solution.closestCost(vector<int>{2, 3}, vector<int> {4, 5, 100}, 18) << endl;
	cout << solution.closestCost(vector<int>{3, 10}, vector<int> {2, 5}, 9) << endl;
	cout << solution.closestCost(vector<int>{10}, vector<int> {1}, 1) << endl;
}
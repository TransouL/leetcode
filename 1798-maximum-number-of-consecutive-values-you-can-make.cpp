#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		sort(coins.begin(), coins.end());
		int ans = 0;
		for (auto &c : coins) {
			if (c <= ans + 1) {
				ans += c;
			}
			else {
				break;
			}
		}
		return ans + 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.getMaximumConsecutive(vector<int> {1, 3}) << endl;
	cout << solution.getMaximumConsecutive(vector<int> {1, 1, 1, 4}) << endl;
	cout << solution.getMaximumConsecutive(vector<int> {1, 4, 10, 3, 1}) << endl;
}
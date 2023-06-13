#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numTimesAllBlue(vector<int>& flips) {
		int n = flips.size(), mx = -1, ans = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, flips[i]);
			if (mx == i + 1) {
				++ans;
				if (mx == n) {
					break;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numTimesAllBlue(vector<int>{3, 2, 4, 1, 5}) << endl;
	cout << solution.numTimesAllBlue(vector<int>{4, 1, 2, 3}) << endl;
}
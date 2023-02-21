#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int stoneGameII(vector<int>& piles) {
		int s = 0, n = piles.size();
		vector<vector<int>> f(n, vector<int>(n + 1));
		for (int i = n - 1; i >= 0; --i) {
			s += piles[i];
			for (int m = 1; m <= i / 2 + 1; ++m) {
				if (i + m * 2 >= n) {
					f[i][m] = s;
				}
				else {
					int mn = INT_MAX;
					for (int x = 1; x <= m * 2; ++x) {
						mn = min(mn, f[i + x][max(m, x)]);
					}
					f[i][m] = s - mn;
				}
			}
		}
		return f[0][1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.stoneGameII(vector<int> {2, 7, 9, 4, 4}) << endl;
	cout << solution.stoneGameII(vector<int> {1, 2, 3, 4, 5, 100}) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> rs(m, vector<int>(n + 1)), cs(n, vector<int>(m + 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				rs[i][j + 1] = rs[i][j] + grid[i][j];
				cs[j][i + 1] = cs[j][i] + grid[i][j];
			}
		}
		for (int d = min(m, n); d > 0; --d) {
			for (int i = 0; i <= m - d; ++i) {
				for (int j = 0; j <= n - d; ++j) {
					if (rs[i][j + d] - rs[i][j] == d &&
						cs[j][i + d] - cs[j][i] == d &&
						rs[i + d - 1][j + d] - rs[i + d - 1][j] == d &&
						cs[j + d - 1][i + d] - cs[j + d - 1][i] == d) {
						return d * d;
					}
				}
			}
		}

		return 0;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.largest1BorderedSquare(vector<vector<int>> {{1, 1, 1}, { 1, 0, 1 }, { 1, 1, 1 }}) << endl;
	cout << solution.largest1BorderedSquare(vector<vector<int>> {{1, 1, 0, 0}}) << endl;
}
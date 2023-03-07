#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int s = min(m, n), l = max(m, n);

		// 先处理掉首行首列，剩余的部分不需要在考虑越界问题
		for (int i = 1; i < m; i++) {
			grid[i][0] += grid[i - 1][0];
		}
		for (int j = 1; j < n; j++) {
			grid[0][j] += grid[0][j - 1];
		}
		// 一共是s轮
		for (int r = 1; r < s; r++) {
			// 先更新本轮的行列交叉点，之后行和列按照各自的大小更新
			grid[r][r] += max(grid[r][r - 1], grid[r - 1][r]);
			for (int i = r + 1; i < m; i++) {
				grid[i][r] += max(grid[i - 1][r], grid[i][r - 1]);
			}
			for (int j = r + 1; j < n; j++) {
				grid[r][j] += max(grid[r][j - 1], grid[r - 1][j]);
			}
		}
		return grid[m - 1][n - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxValue(vector<vector<int>> {{1, 3, 1}, { 1, 5, 1 }, { 4, 2, 1 }}) << endl;
	cout << solution.maxValue(vector<vector<int>> {{1, 2, 5}, { 3, 2, 1 }}) << endl;
}
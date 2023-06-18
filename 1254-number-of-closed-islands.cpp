#include <iostream>
#include <vector>
using namespace std;

class Solution {
	void dfs(vector<vector<int>> &grid, int x, int y) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y])
			return;
		grid[x][y] = 1;
		dfs(grid, x - 1, y);
		dfs(grid, x + 1, y);
		dfs(grid, x, y - 1);
		dfs(grid, x, y + 1);
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			int step = i == 0 || i == m - 1 ? 1 : n - 1;
			for (int j = 0; j < n; j += step) {
				dfs(grid, i, j);
			}
		}

		int ans = 0;
		for (int i = 1; i < m - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (grid[i][j] == 0) {
					++ans;
					dfs(grid, i, j);
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.closedIsland(vector<vector<int>> {{1, 1, 1, 1, 1, 1, 1, 0}, { 1, 0, 0, 0, 0, 1, 1, 0 }, { 1, 0, 1, 0, 1, 1, 1, 0 }, { 1, 0, 0, 0, 0, 1, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 0 }}) << endl;
	cout << solution.closedIsland(vector<vector<int>> {{0, 0, 1, 0, 0}, { 0, 1, 0, 1, 0 }, { 0, 1, 1, 1, 0 }}) << endl;
}
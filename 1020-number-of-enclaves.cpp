#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
	void dfs(vector<vector<int>>& grid, int x, int y, int m, int n){
		grid[x][y] = 0;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1) {
				grid[nx][ny] = 0;
				dfs(grid, nx, ny, m, n);
			}
		}
	}
public:
	int numEnclaves(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			if (grid[i][0] == 1)
				dfs(grid, i, 0, m, n);
			if (grid[i][n - 1] == 1)
				dfs(grid, i, n - 1, m, n);
		}
		for (int j = 1; j < n - 1; j++) {
			if (grid[0][j] == 1)
				dfs(grid, 0, j, m, n);
			if (grid[m - 1][j] == 1)
				dfs(grid, m - 1, j, m, n);
		}
		int ans = 0;
		for (int i = 1; i < m - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (grid[i][j] == 1)
					++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numEnclaves(vector<vector<int>>{ {0, 0, 0, 0}, { 1, 0, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 }}) << endl;
	cout << solution.numEnclaves(vector<vector<int>>{ {0, 1, 1, 0}, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 }}) << endl;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int d[5] = {0, -1, 0, 1, 0};

class Solution {
	bool valid(int n, int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < n;
	}

	int dfs(const vector<vector<int>> &grid, int x, int y, vector<vector<int>> &tag, int t) {
		int n = grid.size(), res = 1;
		tag[x][y] = t;
		for (int i = 0; i < 4; i++) {
			int nx = x + d[i], ny = y + d[i + 1];
			if (valid(n, nx, ny) && grid[nx][ny] == 1 && tag[nx][ny] == 0) {
				res += dfs(grid, nx, ny, tag, t);
			}
		}
		return res;
	}
public:
	int largestIsland(vector<vector<int>> &grid) {
		int n = grid.size(), ans = 0;
		vector<vector<int>> tag(n, vector<int>(n));
		unordered_map<int, int> area;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 && tag[i][j] == 0) {
					int t = i * n + j + 1;
					area[t] = dfs(grid, i, j, tag, t);
					ans = max(ans, area[t]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					int z = 1;
					unordered_set<int> connected;
					for (int k = 0; k < 4; k++) {
						int nx = i + d[k], ny = j + d[k + 1];
						if (!valid(n, nx, ny) || tag[nx][ny] == 0 || connected.count(tag[nx][ny])) {
							continue;
						}
						z += area[tag[nx][ny]];
						connected.emplace(tag[nx][ny]);
					}
					ans = max(ans, z);
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.largestIsland(vector<vector<int>> {{1, 0}, { 0, 1 }}) << endl;
	cout << solution.largestIsland(vector<vector<int>> {{1, 1}, { 0, 1 }}) << endl;
	cout << solution.largestIsland(vector<vector<int>> {{1, 1}, { 1, 1 }}) << endl;
}

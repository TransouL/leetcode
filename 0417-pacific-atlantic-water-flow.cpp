#include <iostream>
#include <vector>

using namespace std;
bool flag1[200][200], flag2[200][200];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
	void dfs(vector<vector<int>>& heights, bool flag[200][200], int x, int y, int m, int n) {
		if (flag[x][y])
			return;
		flag[x][y] = true;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && heights[x][y] <= heights[nx][ny]) {
				dfs(heights, flag, nx, ny, m, n);
			}
		}
	}
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int m = heights.size(), n = heights[0].size();
		memset(flag1, false, sizeof(flag1));
		memset(flag2, false, sizeof(flag1));
		for (int i = 0; i < m; i++) {
			dfs(heights, flag1, i, 0, m, n);
			dfs(heights, flag2, i, n - 1, m, n);
		}
		for (int j = 0; j < n; j++) {
			dfs(heights, flag1, 0, j, m, n);
			dfs(heights, flag2, m - 1, j, m, n);
		}
		vector<vector<int>> ans;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (flag1[i][j] && flag2[i][j]) {
					ans.push_back({ i, j });
				}
			}
		}
		return ans;
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.pacificAtlantic(vector<vector<int>> {{1, 2, 2, 3, 5}, { 3, 2, 3, 4, 4 }, { 2, 4, 5, 3, 1 }, { 6, 7, 1, 4, 5 }, { 5, 1, 1, 2, 4 }}));
}

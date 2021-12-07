#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		int m = grid.size(), n = grid[0].size(), original = grid[row][col];
		vector<pair<int, int>> connected;
		dfs(row, col, m, n, original, grid, connected);

		vector<pair<int, int>> inside;
		for (auto &pair : connected){
			if (0 < pair.first && pair.first < m - 1 && 0 < pair.second && pair.second < n - 1) {
				bool isBorder = false;
				for (size_t d = 0; d < 4; d++) {
					if (grid[pair.first + dx[d]][pair.second + dy[d]] != 0) {
						isBorder = true;
						break;
					}
				}
				if (!isBorder)
					inside.push_back(pair);
			}
		}
		for (auto &pair : connected){
			grid[pair.first][pair.second] = color;
		}
		for (auto &pair : inside){
			grid[pair.first][pair.second] = original;
		}

		return grid;
	}
private:
	void dfs(int row, int col, int m, int n, int color, vector<vector<int>>& grid, vector<pair<int, int>>& connected) {
		connected.push_back(make_pair(row, col));
		grid[row][col] = 0;
		for (size_t d = 0; d < 4; d++) {
			if (0 <= row + dx[d] && row + dx[d] < m && 0 <= col + dy[d] && col + dy[d] < n && grid[row + dx[d]][col + dy[d]] == color) {
				dfs(row + dx[d], col + dy[d], m, n, color, grid, connected);
			}
		}
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e) {
			cout << i << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.colorBorder(vector<vector<int>>{ { 1, 1 }, { 1, 2 } }, 0, 0, 3));
	printVector(solution.colorBorder(vector<vector<int>>{ { 1, 2, 2 }, { 2, 3, 2 } }, 0, 1, 3));
	printVector(solution.colorBorder(vector<vector<int>>{ { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }}, 1, 1, 2));
	printVector(solution.colorBorder(vector<vector<int>>{ { 1, 2, 1, 2, 1, 2 }, { 2, 2, 2, 2, 1, 2 }, { 1, 2, 2, 2, 1, 2 }}, 1, 3, 1));
}
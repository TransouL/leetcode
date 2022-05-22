#include <iostream>
#include <queue>
using namespace std;

int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
class Solution {
	int row, col;
	vector<vector<int>> forest;
	int bfs(int sx, int sy, int tx, int ty) {
		if (sx == tx && sy == ty) {
			return 0;
		}

		int step = 0;
		queue<pair<int, int>> qu;
		vector<vector<bool>> visited(row, vector<bool>(col, false));
		qu.emplace(sx, sy);
		visited[sx][sy] = true;
		while (!qu.empty()) {
			step++;
			int sz = qu.size();
			for (int i = 0; i < sz; ++i) {
				auto p = qu.front();
				qu.pop();
				int cx = p.first, cy = p.second;
				for (int d = 0; d < 4; d++) {
					int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && forest[nx][ny] > 0) {
						if (nx == tx && ny == ty) {
							return step;
						}
						qu.emplace(nx, ny);
						visited[nx][ny] = true;
					}
				}
			}
		}
		return -1;
	}

public:
	int cutOffTree(vector<vector<int>>& forest) {
		this->row = forest.size();
		this->col = forest[0].size();
		this->forest = forest;

		vector<pair<int, int>> trees;
		for (int i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (forest[i][j] > 1) {
					trees.emplace_back(i, j);
				}
			}
		}
		sort(trees.begin(), trees.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
			return forest[a.first][a.second] < forest[b.first][b.second];
		});

		int cx = 0, cy = 0, ans = 0;
		for (int i = 0; i < trees.size(); i++) {
			int steps = bfs(cx, cy, trees[i].first, trees[i].second);
			if (steps == -1) {
				return -1;
			}
			ans += steps;
			cx = trees[i].first;
			cy = trees[i].second;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.cutOffTree(vector<vector<int>>{{1, 2, 3}, { 0, 0, 4 }, { 7, 6, 5 }}) << endl;
}

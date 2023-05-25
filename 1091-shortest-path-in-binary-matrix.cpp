#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
			return -1;
		}
		vector<vector<bool>> dist(n, vector<bool>(n, false));
		queue<pii> q;
		q.emplace(0, 0);
		dist[0][0] = true;
		int curr = 1;
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				pii p = q.front();
				int x = p.first, y = p.second;
				if (x == n - 1 && y == n - 1) {
					return curr;
				}
				q.pop();
				for (int dx = -1; dx <= 1; dx++) {
					for (int dy = -1; dy <= 1; dy++) {
						if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n || (dx == 0 && dy == 0)) {
							continue;
						}
						if (grid[x + dx][y + dy] == 1 || dist[x + dx][y + dy] == true) {
							continue;
						}
						dist[x + dx][y + dy] = true;
						q.emplace(x + dx, y + dy);
					}
				}
			}
			++curr;
		}
		return -1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.shortestPathBinaryMatrix(vector<vector<int>> {{0, 1}, { 1, 0 }}) << endl;
	cout << solution.shortestPathBinaryMatrix(vector<vector<int>> {{0, 0, 0}, { 1, 1, 0 }, { 1, 1, 0 }}) << endl;
	cout << solution.shortestPathBinaryMatrix(vector<vector<int>> {{1, 0, 0}, { 1, 1, 0 }, { 1, 1, 0 }}) << endl;
}
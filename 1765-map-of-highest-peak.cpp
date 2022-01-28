#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int m = isWater.size(), n = isWater[0].size();
		vector<vector<int>> ans(m, vector<int>(n, -1));
		queue<pii> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (isWater[i][j]) {
					ans[i][j] = 0;
					q.emplace(i, j);
				}
			}
		}
		while (!q.empty()) {
			auto &p = q.front();
			for (size_t d = 0; d < 4; d++) {
				int x = p.first + dx[d], y = p.second + dy[d];
				if (0 <= x && x < m && 0 <= y && y < n && ans[x][y] == -1) {
					ans[x][y] = ans[p.first][p.second] + 1;
					q.emplace(x, y);
				}
			}
			q.pop();
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &sv : v)
		for (auto &e : sv) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.highestPeak(vector<vector<int>> {{ 0, 1 }, { 0, 0 }}));
	printVector(solution.highestPeak(vector<vector<int>> {{ 0, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 }}));
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
		for (auto &e : redEdges) {
			next[0][e[0]].push_back(e[1]);
		}
		for (auto &e : blueEdges) {
			next[1][e[0]].push_back(e[1]);
		}

		vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
		queue<pair<int, int>> q;
		dist[0][0] = 0;
		dist[1][0] = 0;
		q.push({ 0, 0 });
		q.push({ 0, 1 });
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			int x = p.first, t = p.second;
			for (auto y : next[1 - t][x]) {
				if (dist[1 - t][y] != INT_MAX) {
					continue;
				}
				dist[1 - t][y] = dist[t][x] + 1;
				q.push({ y, 1 - t });
			}
		}
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = min(dist[0][i], dist[1][i]);
			if (ans[i] == INT_MAX) {
				ans[i] = -1;
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.shortestAlternatingPaths(3, vector<vector<int>>{{1, 2}, { 0, 1 }}, vector<vector<int>>{}));
	printVector(solution.shortestAlternatingPaths(3, vector<vector<int>>{{0, 1}}, vector<vector<int>>{{2, 1}}));
}
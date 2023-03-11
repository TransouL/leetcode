﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj(n);
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
		for (auto &edge : edges) {
			int x = edge[0] - 1;
			int y = edge[1] - 1;
			adj[x].push_back(y);
			adj[y].push_back(x);
			dist[x][y] = dist[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			dist[i][i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (dist[j][i] != INT_MAX && dist[i][k] != INT_MAX) {
						dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
					}
				}
			}
		}

		function<int(int, int, int, int)> dfs = [&](int u, int parent, int x, int y) -> int {
			if (dist[u][x] > dist[x][y] || dist[u][y] > dist[x][y]) {
				return 1;
			}
			if ((dist[u][y] == dist[x][y] && u < x) || (dist[u][x] == dist[x][y] && u < y)) {
				return 1;
			}
			int res = 1;
			for (auto &v : adj[u]) {
				if (v != parent) {
					res *= dfs(v, u, x, y);
				}
			}
			if (dist[u][x] + dist[u][y] > dist[x][y]) {
				++res;
			}
			return res;
		};

		vector<int> ans(n - 1);
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans[dist[i][j] - 1] += dfs(i, -1, i, j);
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
	printVector(solution.countSubgraphsForEachDiameter(4, vector<vector<int>>{{1, 2}, { 2, 3 }, { 2, 4 }}));
	printVector(solution.countSubgraphsForEachDiameter(2, vector<vector<int>>{{1, 2}}));
}
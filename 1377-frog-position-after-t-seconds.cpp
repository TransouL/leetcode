#include <iostream>
#include <vector>
using namespace std;

class Solution {
	double dfs(vector<vector<int>> &G, vector<bool> &visited, int i, int t, int target){
		int nxt = i == 1 ? G[i].size() : G[i].size() - 1;
		if (t == 0 || nxt == 0) {
			return i == target ? 1.0 : 0.0;
		}
		visited[i] = true;
		double ans = 0.0;
		for (auto &j : G[i]) {
			if (!visited[j]) {
				ans += dfs(G, visited, j, t - 1, target);
			}
		}
		return ans / nxt;
	}

public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> G(n + 1);
		for (int i = 0; i < edges.size(); i++) {
			G[edges[i][0]].push_back(edges[i][1]);
			G[edges[i][1]].push_back(edges[i][0]);
		}
		vector<bool> visitied(n + 1, false);
		return dfs(G, visitied, 1, t, target);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.frogPosition(7, vector<vector<int>> {{1, 2}, { 1, 3 }, { 1, 7 }, { 2, 4 }, { 2, 6 }, { 3, 5 }}, 2, 4) << endl;
}
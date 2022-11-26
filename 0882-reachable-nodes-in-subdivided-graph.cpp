#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
	int encode(int u, int v, int n) {
		return u * n + v;
	}
public:
	int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
		vector<vector<pair<int, int>>> adList(n);
		for (auto &edge : edges) {
			int u = edge[0], v = edge[1], nodes = edge[2];
			adList[u].emplace_back(v, nodes);
			adList[v].emplace_back(u, nodes);
		}

		unordered_map<int, int> used;
		unordered_set<int> visited;
		int reachableNodes = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.emplace(0, 0);
		while (!pq.empty() && pq.top().first <= maxMoves) {
			auto p = pq.top();
			int step = p.first, u = p.second;
			pq.pop();
			if (visited.count(u)) {
				continue;
			}
			visited.emplace(u);
			reachableNodes++;
			for (auto &p : adList[u]) {
				int v = p.first, nodes = p.second;
				if (nodes + step + 1 <= maxMoves && !visited.count(v)) {
					pq.emplace(nodes + step + 1, v);
				}
				used[encode(u, v, n)] = min(nodes, maxMoves - step);
			}
		}

		for (auto &edge : edges) {
			int u = edge[0], v = edge[1], nodes = edge[2];
			reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
		}
		return reachableNodes;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.reachableNodes(vector<vector<int>>{{0, 1, 10}, { 0, 2, 1 }, { 1, 2, 2 }}, 6, 3) << endl;
	cout << solution.reachableNodes(vector<vector<int>>{{0, 1, 4}, { 1, 2, 6 }, { 0, 2, 8 }, { 1, 3, 1 }}, 10, 4) << endl;
}
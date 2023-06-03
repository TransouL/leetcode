#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
	int dis[100][2], delta, vis[100];

public:
	vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
		vector<vector<pii>> g(n);
		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0], y = edges[i][1];
			g[x].emplace_back(y, i);
			g[y].emplace_back(x, i);
		}

		memset(dis, 0x3f, sizeof(dis));
		dis[source][0] = dis[source][1] = 0;
		auto dijkstra = [&](int k) {
			memset(vis, 0, sizeof(vis));
			for (;;) {
				int x = -1;
				for (int i = 0; i < n; i++) {
					if (!vis[i] && (x < 0 || dis[i][k] < dis[x][k])) {
						x = i;
					}
				}
				if (x == destination)
					return;
				vis[x] = true;
				for (auto p : g[x]) {
					int y = p.first, eid = p.second;
					int wt = edges[eid][2];
					if (wt == -1)
						wt = 1;
					if (k == 1 && edges[eid][2] == -1) {
						int w = delta + dis[y][0] - dis[x][1];
						if (w > wt) {
							edges[eid][2] = wt = w;
						}
					}
					dis[y][k] = min(dis[y][k], dis[x][k] + wt);
				}
			}
		};

		dijkstra(0);
		delta = target - dis[destination][0];
		if (delta < 0)
			return{};

		dijkstra(1);
		if (dis[destination][1] < target)
			return{};

		for (auto & e : edges) {
			if (e[2] == -1)
				e[2] = 1;
		}
		return edges;
	}
};

template<typename T>
void printVector(const vector<vector<T>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.modifiedGraphEdges(5, vector<vector<int>>{{4, 1, -1}, { 2, 0, -1 }, { 0, 3, -1 }, { 4, 3, -1 }}, 0, 1, 5));
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		vector<vector<int>> graph(n + 1);
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}

		vector<vector<int>> path(n + 1, vector<int>(2, INT_MAX));
		path[1][0] = 0;
		queue<pii> q;
		q.push({ 1, 0 });
		while (path[n][1] == INT_MAX) {
			pii p =  q.front();
			int curr = p.first, len = p.second;
			q.pop();
			for (auto next : graph[curr]) {
				if (len + 1 < path[next][0]) {
					path[next][0] = len + 1;
					q.push({ next, len + 1 });
				}
				else if (len + 1 > path[next][0] && len + 1 < path[next][1]) {
					path[next][1] = len + 1;
					q.push({ next, len + 1 });
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < path[n][1]; ++i) {
			if (ans % (2 * change) >= change) {
				ans += 2 * change - ans % (2 * change);
			}
			ans += time;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.secondMinimum(5, vector<vector<int>> {{1, 2}, { 1, 3 }, { 1, 4 }, { 3, 4 }, { 4, 5 }}, 3, 5) << endl;
	cout << solution.secondMinimum(2, vector<vector<int>> {{1, 2}}, 3, 2) << endl;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
		int n = patience.size();
		vector<vector<int>> adj(n);
		vector<bool> visited(n, false);
		for (auto &edge : edges) {
			adj[edge[0]].emplace_back(edge[1]);
			adj[edge[1]].emplace_back(edge[0]);
		}

		queue<int> qu;
		qu.emplace(0);
		visited[0] = true;
		int currDis = 1, ans = 0;
		while (!qu.empty()) {
			int currDisCount = qu.size();
			for (int i = 0; i < currDisCount; i++) {
				int currNode = qu.front();
				qu.pop();
				for (auto &nextNode : adj[currNode]) {
					if (visited[nextNode])
						continue;
					qu.emplace(nextNode);
					int p = patience[nextNode], msgs = (currDis * 2 - 1) / p + 1;
					ans = max(ans, p * (msgs - 1) + currDis * 2 + 1);
					visited[nextNode] = true;
				}
			}
			++currDis;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.networkBecomesIdle(vector<vector<int>> {{0, 1}, { 1, 2 }}, vector<int> {0, 2, 1}) << endl;
	cout << solution.networkBecomesIdle(vector<vector<int>> {{0, 1}, { 0, 2 }, { 1, 2 }}, vector<int> {0, 10, 10}) << endl;
}

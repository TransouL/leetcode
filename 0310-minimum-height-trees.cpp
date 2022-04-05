#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) {
			return { 0 };
		}
		vector<int> degree(n);
		vector<unordered_set<int>> adj(n);
		for (auto &edge : edges) {
			adj[edge[0]].emplace(edge[1]);
			adj[edge[1]].emplace(edge[0]);
			++degree[edge[0]];
			++degree[edge[1]];
		}

		queue<int> qu;
		for (int i = 0; i < n; i++) {
			if (degree[i] == 1)
				qu.emplace(i);
		}
		int remainNodes = n;
		while (remainNodes > 2) {
			int sz = qu.size();
			remainNodes -= sz;
			for (int i = 0; i < sz; i++) {
				int curr = qu.front();
				qu.pop();
				for (auto &node : adj[curr]) {
					if (--degree[node] == 1) {
						qu.emplace(node);
					}
				}
			}
		}
		
		vector<int> ans;
		while (!qu.empty()) {
			ans.emplace_back(qu.front());
			qu.pop();
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findMinHeightTrees(4, vector<vector<int>>{{1, 0}, { 1, 2 }, { 1, 3 }}));
	printVector(solution.findMinHeightTrees(6, vector<vector<int>>{{3, 0}, { 3, 1 }, { 3, 2 }, { 3, 4 }, { 5, 4 }}));
}

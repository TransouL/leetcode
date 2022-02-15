#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int checkWays(vector<vector<int>>& pairs) {
		unordered_map<int, unordered_set<int>> adj;
		for (auto &p : pairs) {
			adj[p[0]].emplace(p[1]);
			adj[p[1]].emplace(p[0]);
		}
		// 检测是否存在根节点
		int root = -1;
		for (auto &entry : adj) {
			if (entry.second.size() == adj.size() - 1) {
				root = entry.first;
				break;
			}
		}
		if (root == -1) {
			return 0;
		}

		int ans = 1;
		for (auto &entry : adj) {
			if (entry.first == root) {
				continue;
			}
			unordered_set<int> neighbours = entry.second;
			int currDegree = neighbours.size();
			int parent = -1;
			int parentDegree = INT_MAX;

			// 根据 degree 的大小找到 node 的父节点 parent
			for (auto &nei : neighbours) {
				if (adj[nei].size() < parentDegree && adj[nei].size() >= currDegree) {
					parent = nei;
					parentDegree = adj[nei].size();
				}
			}
			if (parent == -1) {
				return 0;
			}

			// 检测 neighbours 是否是 adj[parent] 的子集
			for (auto &nei : neighbours) {
				if (nei == parent) {
					continue;
				}
				if (!adj[parent].count(nei)) {
					return 0;
				}
			}

			if (parentDegree == currDegree) {
				ans = 2; // 这里不能直接return 2，因为还需要check其他node是否合法，即不会再返回1了，但是还有返回0的可能
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.checkWays(vector<vector<int>>{{1, 2}, { 2, 3 }}) << endl;
	cout << solution.checkWays(vector<vector<int>>{{1, 2}, { 2, 3 }, { 1, 3 }}) << endl;
	cout << solution.checkWays(vector<vector<int>>{{1, 2}, { 2, 3 }, { 2, 4 }, { 1, 5 }}) << endl;
}

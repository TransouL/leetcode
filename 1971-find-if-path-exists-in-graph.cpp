#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<int> fa;
	int find(int x) {
		if (fa[x] != x) {
			fa[x] = find(fa[x]);
		}
		return fa[x];
	}
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		fa = vector<int>(n);
		for (int i = 0; i < n; i++) {
			fa[i] = i;
		}
		for (auto &edge : edges) {
			merge(edge[0], edge[1]);
		}
		return find(source) == find(destination);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.validPath(3, vector<vector<int>> {{0, 1}, { 1, 2 }, { 2, 0 }}, 0, 2) << endl;
	cout << solution.validPath(6, vector<vector<int>> {{0, 1}, { 0, 2 }, { 3, 5 }, { 5, 4 }, { 4, 3 }}, 0, 5) << endl;
}
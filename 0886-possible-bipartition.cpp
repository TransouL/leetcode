#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<vector<int>> g;
	vector<int> flag;
	bool dfs(int curr, int color) {
		flag[curr] = color;
		for (auto &next : g[curr]) {
			if (flag[next]) {
				if (flag[next] == flag[curr]) {
					return false;
				}
			}
			else {
				if (!dfs(next, 3 ^ color)) {
					return false;
				}
			}
		}
		return true;
	}
public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		g = vector<vector<int>>(n + 1);
		flag = vector<int>(n + 1, 0);
		for (auto &dislike : dislikes) {
			g[dislike[0]].push_back(dislike[1]);
			g[dislike[1]].push_back(dislike[0]);
		}
		for (int i = 1; i <= n; i++) {
			if (flag[i] == 0 && !dfs(i, 1)) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.possibleBipartition(4, vector<vector<int>> {{1, 2}, { 1, 3 }, { 2, 4 }}) << endl;
	cout << solution.possibleBipartition(3, vector<vector<int>> {{1, 2}, { 1, 3 }, { 2, 3 }}) << endl;
	cout << solution.possibleBipartition(5, vector<vector<int>> {{1, 2}, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 1, 5 }}) << endl;
}

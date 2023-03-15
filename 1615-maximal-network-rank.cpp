#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		vector<vector<bool>> connect(n, vector<bool>(n, false));
		vector<int> degree(n, 0);
		for (auto v : roads) {
			connect[v[0]][v[1]] = true;
			connect[v[1]][v[0]] = true;
			degree[v[0]]++;
			degree[v[1]]++;
		}

		int maxRank = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
				maxRank = max(maxRank, rank);
			}
		}
		return maxRank;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maximalNetworkRank(4, vector<vector<int>>{{0, 1 }, { 0, 3 }, { 1, 2 }, { 1, 3 }}) << endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<vector<bool>, int> stats;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; i++) {
			vector<bool> feature(n);
			for (int j = 0; j < n; j++) {
				if (matrix[i][0]) {
					if (matrix[i][j] == 1) {
						feature[j] = true;
					}
				}
				else {
					if (matrix[i][j] == 0) {
						feature[j] = true;
					}
				}
			}
			++stats[feature];
		}
		int ans = 0;
		for (auto &entry : stats) {
			if (ans < entry.second) {
				ans = entry.second;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxEqualRowsAfterFlips(vector<vector<int>>{{0, 1}, { 1, 1 }}) << endl;
	cout << solution.maxEqualRowsAfterFlips(vector<vector<int>>{{0, 1}, { 1, 0 }}) << endl;
	cout << solution.maxEqualRowsAfterFlips(vector<vector<int>>{{0, 0, 0}, { 0, 0, 1 }, { 1, 1, 0 }}) << endl;
}
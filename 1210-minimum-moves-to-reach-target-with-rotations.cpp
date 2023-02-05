#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	const int INVALID = INT_MAX / 2;
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(2, INVALID)));
		f[0][0][0] = 0;
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				bool canH = (j + 1 < n && grid[i][j] == 0 && grid[i][j + 1] == 0);
				bool canV = (i + 1 < n && grid[i][j] == 0 && grid[i + 1][j] == 0);
				if (i - 1 >= 0 && canH) {
					f[i][j][0] = min(f[i][j][0], f[i - 1][j][0] + 1);
				}
				if (j - 1 >= 0 && canH) {
					f[i][j][0] = min(f[i][j][0], f[i][j - 1][0] + 1);
				}
				if (i - 1 >= 0 && canV) {
					f[i][j][1] = min(f[i][j][1], f[i - 1][j][1] + 1);
				}
				if (j - 1 >= 0 && canV) {
					f[i][j][1] = min(f[i][j][1], f[i][j - 1][1] + 1);
				}
				if (canH && canV && grid[i + 1][j + 1] == 0) {
					f[i][j][0] = min(f[i][j][0], f[i][j][1] + 1);
					f[i][j][1] = min(f[i][j][1], f[i][j][0] + 1);
				}
			}
		}

		return (f[n - 1][n - 2][0] == INVALID ? -1 : f[n - 1][n - 2][0]);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumMoves(vector<vector<int>> {{0, 0, 0, 0, 0, 1}, { 1, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0, 1, 1 }, { 0, 0, 1, 0, 1, 0 }, { 0, 1, 1, 0, 0, 0 }, { 0, 1, 1, 0, 0, 0 }}) << endl;
}
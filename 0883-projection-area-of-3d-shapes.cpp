#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int n = grid.size();
		int ans = 0;
		vector<int> z(n, 0);
		for (int i = 0; i < n; i++) {
			int maxY = 0;
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					ans += 1;
				}
				maxY = max(maxY, grid[i][j]);
				z[j] = max(z[j], grid[i][j]);
			}
			ans += maxY;
		}
		for (auto &e : z) {
			ans += e;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.projectionArea(vector<vector<int>> {{1, 2}, { 3, 4 }}) << endl;
	cout << solution.projectionArea(vector<vector<int>> {{2}}) << endl;
	cout << solution.projectionArea(vector<vector<int>> {{1, 0}, { 0, 2 }}) << endl;
}

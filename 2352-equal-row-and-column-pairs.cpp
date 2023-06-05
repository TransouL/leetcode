#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {
		int n = grid.size();
		map<vector<int>, int> cnt;
		for (auto &row : grid) {
			++(cnt[row]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<int> column(n);
			for (int j = 0; j < n; j++) {
				column[j] = grid[j][i];
			}
			ans += cnt[column];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.equalPairs(vector<vector<int>>{{3, 2, 1}, { 1, 7, 6 }, { 2, 7, 7 }}) << endl;
	cout << solution.equalPairs(vector<vector<int>>{{3, 1, 2, 2}, { 1, 4, 4, 5 }, { 2, 4, 2, 2 }, { 2, 4, 2, 2}}) << endl;
}
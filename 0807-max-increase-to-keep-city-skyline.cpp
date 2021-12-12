#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int skylineH[50], skylineV[50];

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		size_t n = grid.size();
		memset(skylineH, 0, sizeof(int) * n);
		memset(skylineV, 0, sizeof(int) * n);
		for (size_t i = 0; i < n; ++i){
			for (size_t j = 0; j < n; ++j) {
				skylineH[i] = max(skylineH[i], grid[i][j]);
				skylineV[j] = max(skylineV[j], grid[i][j]);
			}
		}

		int ans = 0;
		for (size_t i = 0; i < n; ++i){
			for (size_t j = 0; j < n; ++j) {
				ans += min(skylineH[i], skylineV[j]) - grid[i][j];
			}
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxIncreaseKeepingSkyline(vector<vector<int>>{{3, 0, 8, 4}, { 2, 4, 5, 7 }, { 9, 2, 6, 3 }, { 0, 3, 1, 0 }}) << endl;
}
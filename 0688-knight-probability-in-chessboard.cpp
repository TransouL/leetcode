#include <iostream>

using namespace std;

int dx[8] = { -2, -2, 2, 2, -1, -1, 1, 1 };
int dy[8] = { -1, 1, -1, 1, -2, 2, -2, 2 };
double dp[101][26][26];

class Solution {
public:
	double knightProbability(int n, int k, int row, int column) {
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < n; ++j)
				dp[0][i][j] = 1.0;
		for (size_t step = 1; step <= k; ++step) {
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < n; ++j) {
					double inPossible = 0.0;
					for (size_t d = 0; d < 8; d++) {
						int ni = i + dx[d], nj = j + dy[d];
						if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
							inPossible += dp[step - 1][ni][nj] / 8;
						}
					}
					dp[step][i][j] = inPossible;
				}
			}
		}
		return dp[k][row][column];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.knightProbability(3, 2, 0, 0) << endl;
	cout << solution.knightProbability(1, 0, 0, 0) << endl;
	cout << solution.knightProbability(1, 1, 0, 0) << endl;
}

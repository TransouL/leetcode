#include <iostream>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int dp[1000][1000] = { 0 };
int calculated = -1;

class Solution {
public:
	int getMoneyAmount(int n) {
		if (calculated == -1){
			for (int i = 0; i < 1000; i++){
				for (int j = i + 1; j < 1000; j++){
					dp[i][j] = INT_MAX;
				}
			}
		}

		if (n > calculated) {
			for (int j = calculated + 1; j <= n; j++){
				for (int i = j - 1; i >= 1; i--){
					for (int k = i; k <= j; k++){
						dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
					}
				}
			}
			calculated = n;
		}
		return dp[1][n];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.getMoneyAmount(5) << endl;
	cout << solution.getMoneyAmount(10) << endl;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		unordered_map<int, int> indices;
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			indices[arr[i]] = i;
		}
		vector<vector<int>> dp(n, vector<int>(n));
		int ans = 0;
		for (int i = 2; i < n; i++) {
			for (int j = i - 1; j >= 1 && arr[j] * 2 > arr[i]; --j) {
				int prev = arr[i] - arr[j];
				if (indices.count(prev)) {
					int k = indices[prev];
					dp[j][i] = max(dp[k][j] + 1, 3);
				}
				ans = max(ans, dp[j][i]);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.lenLongestFibSubseq(vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8 }) << endl;
	cout << solution.lenLongestFibSubseq(vector<int>{ 1, 3, 7, 11, 12, 14, 18 }) << endl;
	cout << solution.lenLongestFibSubseq(vector<int>{ 2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50 }) << endl; // 5
}

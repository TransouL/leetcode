#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestArithSeqLength(vector<int>& a) {
		int ans = 0, n = a.size();
		vector<int[1001]> f(n);
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				int d = a[i] - a[j] + 500;
				if (f[i][d] == 0) {
					f[i][d] = f[j][d] + 1;
					ans = max(ans, f[i][d]);
				}
			}
		}
		return ans + 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.longestArithSeqLength(vector<int> {3, 6, 9, 12}) << endl;
	cout << solution.longestArithSeqLength(vector<int> {9, 4, 7, 2, 10}) << endl;
	cout << solution.longestArithSeqLength(vector<int> {20, 1, 15, 3, 10, 5, 8}) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int mergeStones(vector<int>& stones, int k) {
		int n = stones.size();
		if ((n - 1) % (k - 1) != 0) {
			return -1;
		}

		vector<int> pre(n + 1, 0);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = pre[i] + stones[i];
		}

		int f[30][30];
		for (int i = n - 1; i >= 0; --i) {
			f[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				f[i][j] = INT_MAX;
				for (int m = i; m < j; m += k - 1) {
					f[i][j] = min(f[i][j], f[i][m] + f[m + 1][j]);
				}
				if ((j - i) % (k - 1) == 0) {
					f[i][j] += pre[j + 1] - pre[i];
				}
			}
		}
		return f[0][n - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.mergeStones(vector<int> {3, 2, 4, 1}, 2) << endl;
	cout << solution.mergeStones(vector<int> {3, 2, 4, 1}, 3) << endl;
	cout << solution.mergeStones(vector<int> {3, 5, 1, 2, 6}, 3) << endl;
}
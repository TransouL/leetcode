#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> f(n + 1);
		f[0] = 0;
		for (int i = 0; i < n; i++) {
			f[i + 1] = 0;
			for (int j = i, mx = 0; j > i - k && j >= 0 ; --j) {
				mx = max(mx, arr[j]); //
				f[i + 1] = max(f[i + 1], f[j] + (i - j + 1) * mx);
			}
		}
		return f[n];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxSumAfterPartitioning(vector<int>{1, 15, 7, 9, 2, 5, 10}, 3) << endl;
	cout << solution.maxSumAfterPartitioning(vector<int>{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3}, 4) << endl;
	cout << solution.maxSumAfterPartitioning(vector<int>{1}, 1) << endl;
}
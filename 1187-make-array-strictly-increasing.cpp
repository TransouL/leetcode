#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
		a.push_back(INT_MAX);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		int n = a.size();
		vector<int> f(n);
		for (int i = 0; i < n; i++) {
			int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			int res = k < i ? INT_MIN : 0;
			if (i && a[i - 1] < a[i]) {
				res = max(res, f[i - 1]);
			}
			for (int j = i - 2; j > i - k - 1 && j >= 0; --j) {
				if (b[k - (i - j - 1)] > a[j]) {
					res = max(res, f[j]);
				}
			}
			f[i] = res + 1;
		}
		return f[n - 1] < 0 ? -1 : n - f[n - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.makeArrayIncreasing(vector<int>{1, 5, 3, 6, 7}, vector<int>{1, 3, 2, 4}) << endl;
	cout << solution.makeArrayIncreasing(vector<int>{1, 5, 3, 6, 7}, vector<int>{4, 3, 1}) << endl;
	cout << solution.makeArrayIncreasing(vector<int>{1, 5, 3, 6, 7}, vector<int>{1, 6, 3, 3}) << endl;
}
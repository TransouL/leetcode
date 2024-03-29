﻿#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
	unordered_set<int> seen;
	string ans;
	int highest;
	int k;

	void dfs(int node) {
		for (int x = 0; x < k; ++x) {
			int nei = node * 10 + x;
			if (!seen.count(nei)) {
				seen.insert(nei);
				dfs(nei % highest);
				ans += (x + '0');
			}
		}
	}
public:
	string crackSafe(int n, int k) {
		highest = pow(10, n - 1);
		this->k = k;
		dfs(0);
		ans += string(n - 1, '0');
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.crackSafe(1, 2) << endl;
	cout << solution.crackSafe(2, 2) << endl;
}
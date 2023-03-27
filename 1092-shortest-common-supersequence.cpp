#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string shortestCommonSupersequence(string s, string t) {
		int n = s.length(), m = t.length(), f[n + 1][m + 1];
		for (int j = 0; j < m; j++) f[0][j] = j;
		for (int i = 1; i < n; i++) f[i][0] = i;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i] == t[j])
					f[i + 1][j + 1] = f[i][j] + 1;
				else
					f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1;
			}
		}
		string ans;
		int i = n - 1, j = m - 1;
		while (i >= 0 && j >= 0) {
			if (s[i] == t[j]) {
				ans += s[i];
				--i;
				--j;
			}
			else if (f[i + 1][j + 1] == f[i][j + 1] + 1)
				ans += s[i--];
			else
				ans += t[j--];
		}
		reverse(ans.begin(), ans.end());
		return s.substr(0, i + 1) + t.substr(0, j + 1) + ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.shortestCommonSupersequence("abac", "cab") << endl;
}
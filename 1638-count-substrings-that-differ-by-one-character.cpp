#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countSubstrings(string s, string t) {
		int ans = 0, n = s.size(), m = t.size();
		for (int d = 1 - m; d < n; d++) {
			int i = max(d, 0);
			for (int k0 = i - 1, k1 = k0; i < n && i - d < m; ++i) {
				if (s[i] != t[i - d]) {
					k0 = k1, k1 = i;
				}
				ans += k1 - k0;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countSubstrings("aba", "baba") << endl;
	cout << solution.countSubstrings("ab", "bb") << endl;
	cout << solution.countSubstrings("a", "a") << endl;
	cout << solution.countSubstrings("abe", "bbc") << endl;
}
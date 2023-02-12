#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	bool check(int (&cnt)[26], int partial) {
		return !(cnt['Q' - 'A'] > partial || cnt['W' - 'A'] > partial || cnt['E' - 'A'] > partial || cnt['R' - 'A'] > partial);
	}
public:
	int balancedString(string s) {
		int cnt[26] = { 0 };
		for (auto &ch : s) {
			++cnt[ch - 'A'];
		}

		int partial = s.size() / 4;
		if (check(cnt, partial)) {
			return 0;
		}

		int n = s.size(), ans = n;
		for (int l = 0, r = 0; l < n; l++) {
			while (r < n && !check(cnt, partial)) {
				--cnt[s[r] - 'A'];
				++r;
			}
			if (!check(cnt, partial)) {
				break;
			}
			ans = min(ans, r - l);
			++cnt[s[l] - 'A'];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.balancedString("QWER") << endl;
	cout << solution.balancedString("QQWE") << endl;
	cout << solution.balancedString("QQQW") << endl;
	cout << solution.balancedString("QQQQ") << endl;
}
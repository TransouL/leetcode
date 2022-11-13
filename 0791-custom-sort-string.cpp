#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string customSortString(string order, string s) {
		int cnt[26] = {0};
		for (auto &ch : s) {
			++cnt[ch - 'a'];
		}
		string ans;
		for (auto &ch : order) {
			if (cnt[ch - 'a'] != 0) {
				ans.append(cnt[ch - 'a'], ch);
				cnt[ch - 'a'] = 0;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] != 0) {
				ans.append(cnt[i], 'a' + i);
			}
		}

		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.customSortString("cba", "abcd") << endl;
	cout << solution.customSortString("cbafg", "abcd") << endl;
}
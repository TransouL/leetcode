#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		bool flag[26] = { false };
		for (auto &ch : allowed) {
			flag[ch - 'a'] = true;
		}
		int ans = 0;
		for (auto &word : words) {
			bool tmp = true;
			for (auto &ch : word) {
				if (!flag[ch - 'a']) {
					tmp = false;
					break;
				}
			}
			if (tmp) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countConsistentStrings("ab", vector<string>{ "ad", "bd", "aaab", "baa", "badab" }) << endl;
	cout << solution.countConsistentStrings("abc", vector<string>{ "a", "b", "c", "ab", "ac", "bc", "abc" }) << endl;
	cout << solution.countConsistentStrings("cad", vector<string>{ "cc", "acd", "b", "ba", "bac", "bad", "ac", "d" }) << endl;
}
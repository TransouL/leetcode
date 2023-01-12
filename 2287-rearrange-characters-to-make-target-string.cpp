#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rearrangeCharacters(string s, string target) {
		int scnt[26] = { 0 }, tcnt[26] = { 0 };
		for (auto &ch : s) {
			++scnt[ch - 'a'];
		}
		for (auto &ch : target) {
			++tcnt[ch - 'a'];
		}
		int ans = 100;
		for (int i = 0; i < 26; i++) {
			if (tcnt[i] != 0) {
				ans = min(ans, scnt[i] / tcnt[i]);
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.rearrangeCharacters("ilovecodingonleetcode", "code") << endl;
	cout << solution.rearrangeCharacters("abcba", "abc") << endl;
	cout << solution.rearrangeCharacters("abbaccaddaeea", "aaaaa") << endl;
}
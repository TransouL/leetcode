#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		int cnt[26] = {0};
		int start, len = 0;
		p += ' ';
		char curr = ' ';
		for (auto &ch : p) {
			if (ch == curr + 1 || (curr == 'z' && ch == 'a')) {
				++len;
				curr = ch;
			}
			else {
				if (len != 0) {
					for (int i = 0; i < len && i < 26; i++) {
						int index = (start + i) % 26;
						cnt[index] = max(cnt[index], len - i);
					}
				}
				start = ch - 'a';
				curr = ch;
				len = 1;
			}
		}
		int ans = 0;
		for (auto &i : cnt) {
			ans += i;
		}
		return ans;

	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findSubstringInWraproundString("a") << endl;
	cout << solution.findSubstringInWraproundString("cac") << endl;
	cout << solution.findSubstringInWraproundString("zab") << endl;
}

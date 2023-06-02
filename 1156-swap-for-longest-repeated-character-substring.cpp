#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxRepOpt1(string text) {
		unordered_map<char, int> count;
		for (auto c : text) {
			++count[c];
		}
		int ans = 0, n = text.size();
		for (int i = 0; i < n;) {
			if (n - i < ans) {
				break;
			}

			int j = i + 1;
			while (j < n && text[j] == text[i]) {
				++j;
			}

			int k = j + 1;
			while (k < n && text[k] == text[i]) {
				++k;
			}
			ans = max(ans, min(k - i, count[text[i]]));
			i = j;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxRepOpt1("ababa") << endl;
	cout << solution.maxRepOpt1("aaabaaa") << endl;
	cout << solution.maxRepOpt1("aaabbaaa") << endl;
	cout << solution.maxRepOpt1("aaaaa") << endl;
	cout << solution.maxRepOpt1("abcdef") << endl;
	cout << solution.maxRepOpt1("aaabaaabbaaaaaaa") << endl; // 8
}
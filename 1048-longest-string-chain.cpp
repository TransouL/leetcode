#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), [](const string &a, const string &b) {
			return a.length() < b.length();
		});

		int ans = 0;
		unordered_map<string, int> f;
		for (auto &s : words) {
			int res = 0;
			for (int i = 0; i < s.size(); i++) {
				auto it = f.find(s.substr(0, i) + s.substr(i + 1));
				if (it != f.end()) {
					res = max(res, it->second);
				}
			}
			ans = max(ans, f[s] = res + 1);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.longestStrChain(vector<string>{"a", "b", "ba", "bca", "bda", "bdca"}) << endl;
	cout << solution.longestStrChain(vector<string>{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"}) << endl;
	cout << solution.longestStrChain(vector<string>{"abcd", "dbqca"}) << endl;
}
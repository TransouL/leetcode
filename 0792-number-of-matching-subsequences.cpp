#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		vector<vector<int>> pos(26);
		for (int i = 0; i < s.size(); i++) {
			pos[s[i] - 'a'].push_back(i);
		}
		int ans = words.size();
		for (auto &word : words) {
			if (word.size() > s.size()) {
				--ans;
				continue;
			}

			int p = -1;
			for (auto ch : word) {
				auto &chPos = pos[ch - 'a'];
				auto it = upper_bound(chPos.begin(), chPos.end(), p);
				if (it == chPos.end()) {
					--ans;
					break;
				}
				p = *it;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numMatchingSubseq("abcde", vector<string> {"a", "bb", "acd", "ace"}) << endl;
	cout << solution.numMatchingSubseq("dsahjpjauf", vector<string> {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"}) << endl;
}
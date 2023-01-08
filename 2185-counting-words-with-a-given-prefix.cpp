#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int prefixCount(vector<string>& words, string pref) {
		int ans = 0, ps = pref.size();
		for (auto &word : words) {
			if (word.size() >= ps) {
				bool match = true;
				for (int i = 0; i < ps; i++) {
					if (pref[i] != word[i]) {
						match = false;
						break;
					}
				}
				if (match) {
					++ans;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.prefixCount(vector<string>{"pay", "attention", "practice", "attend"}, "at") << endl;
	cout << solution.prefixCount(vector<string>{"leetcode", "win", "loops", "success"}, "code") << endl;
}
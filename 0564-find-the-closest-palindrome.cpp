#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	vector<long> getCandidates(const string& n) {
		int len = n.length();
		vector<long> candidates = { (long)pow(10, len - 1) - 1, (long)pow(10, len) + 1 };
		long selfPrefix = stol(n.substr(0, (len + 1) / 2));
		for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}){
			string prefix = to_string(i);
			string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
			candidates.emplace_back(stol(candidate));
		}
		return candidates;
	}

public:
	string nearestPalindromic(string n) {
		long selfNumber = stol(n), ans = -1;
		const vector<long>& candidates = getCandidates(n);
		for (auto &cand : candidates) {
			if (cand != selfNumber) {
				if (ans == -1 ||
					abs(cand - selfNumber) < abs(ans - selfNumber) ||
					(cand - selfNumber) == (selfNumber - ans) && cand < ans) {
					ans = cand;
				}
			}
		}
		return to_string(ans);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.nearestPalindromic("123") << endl;
	cout << solution.nearestPalindromic("1") << endl;
	cout << solution.nearestPalindromic("99321") << endl;
	cout << solution.nearestPalindromic("100") << endl;
	cout << solution.nearestPalindromic("12399") << endl;
	cout << solution.nearestPalindromic("998") << endl;
}

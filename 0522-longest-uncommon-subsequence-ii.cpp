#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
	bool checkInclude(string prev, string curr) {
		int prevI = 0;
		for (auto &ch : curr){
			while (prev[prevI] != ch && prevI < prev.size()) {
				++prevI;
			}
			if (prevI == prev.size()) {
				return false;
			}
			else {
				++prevI;
			}
		}
		return true;
	}

public:
	int findLUSlength(vector<string>& strs) {
		int n = strs.size();
		auto cmp = [&](const string &x, string &y) {
			if (x.size() > y.size())
				return true;
			else if (x.size() == y.size())
				return x < y;
			return false;
		};
		sort(strs.begin(), strs.end(), cmp);

		unordered_set<string> visited;
		for (int i = 0; i < n; i++) {
			string curr = strs[i];
			if (visited.count(curr)) {
				continue;
			}
			bool included = false;
			for (auto &prev : visited) {
				if (checkInclude(prev, curr)) {
					included = true;
					break;
				}
			}
			if (!included) {
				if (i == n - 1 || curr != strs[i + 1]){
					return curr.size();
				}
				visited.emplace(curr);
			}
		}
		return -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findLUSlength(vector<string>{ {"aba", "cdc", "eae"} }) << endl;
	cout << solution.findLUSlength(vector<string>{ {"aaa", "aaa", "aa"} }) << endl;
	cout << solution.findLUSlength(vector<string>{ {"aabbcc", "aabbcc", "cb"} }) << endl; // 2
}
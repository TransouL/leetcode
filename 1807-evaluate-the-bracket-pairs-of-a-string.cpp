#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		unordered_map<string, string> mapping;
		for (auto &k : knowledge) {
			mapping.emplace(k[0], k[1]);
		}
		string ans = "";
		int left = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				left = i;
			}
			else if (s[i] == ')') {
				string key = s.substr(left + 1, i - left - 1);
				if (mapping.count(key)) {
					ans += mapping[key];
				}
				else {
					ans += '?';
				}
				left = -1;
			}
			else if (left == -1) {
				ans += s[i];
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.evaluate("(name)is(age)yearsold", vector<vector<string>>{{"name", "bob"}, { "age", "two" }}) << endl;
	cout << solution.evaluate("hi(name)", vector<vector<string>>{{ "a", "b" }}) << endl;
	cout << solution.evaluate("(a)(a)(a)aaa", vector<vector<string>>{{"a", "yes"}}) << endl;
}
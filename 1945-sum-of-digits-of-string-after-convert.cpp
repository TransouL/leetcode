#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int getLucky(string s, int k) {
		string ans_str = "";
		for (auto &c : s) {
			ans_str += to_string(c - 'a' + 1);
		}
		int ans;
		while (k-- > 0) {
			ans = 0;
			for (auto &c : ans_str) {
				ans += (c - '0');
			}
			ans_str = to_string(ans);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.getLucky("iiii", 1) << endl;
	cout << solution.getLucky("leetcode", 2) << endl;
}
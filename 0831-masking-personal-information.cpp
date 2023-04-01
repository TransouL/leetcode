#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

static const string country[4] = { "", "+*-", "+**-", "+***-" };
class Solution {
public:
	string maskPII(string s) {
		int at = s.find("@");
		if (at != string::npos){
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			return s.substr(0, 1) + "*****" + s.substr(at - 1);
		}
		s = regex_replace(s, regex("[^0-9]"), "");
		return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maskPII("LeetCode@LeetCode.com") << endl;
	cout << solution.maskPII("AB@qq.com") << endl;
	cout << solution.maskPII("1(234)567-890") << endl;
	cout << solution.maskPII("86-(10)12345678") << endl;
}
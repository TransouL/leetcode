#include <iostream>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		while (true) {
			int i = s.find("abc");
			if (i != string::npos) {
				s = s.substr(0, i) + s.substr(i + 3);
			}
			else {
				break;
			}
		}
		return s == "";
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.isValid("aabcbc") << endl;
	cout << solution.isValid("abcabcababcc") << endl;
	cout << solution.isValid("abccba") << endl;
}
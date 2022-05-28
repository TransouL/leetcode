#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string removeOuterParentheses(string s) {
		string ans;
		int curr = 0, start = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				++curr;
			}
			else {
				--curr;
				if (curr == 0) {
					ans += s.substr(start + 1, i - start - 1);
					start = i + 1;
					curr = 0;
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.removeOuterParentheses("(()())(())") << endl;
	cout << solution.removeOuterParentheses("(()())(())(()(()))") << endl;
	cout << solution.removeOuterParentheses("()()") << endl;
}

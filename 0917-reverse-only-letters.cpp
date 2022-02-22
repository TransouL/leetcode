#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseOnlyLetters(string s) {
		string ans;
		int n = s.size(), r = n - 1;
		for (int i = 0; i < n; ++i) {
			if (!isalpha(s[i])){
				ans.push_back(s[i]);
			}
			else {
				while (!isalpha(s[r])){
					--r;
				}
				ans.push_back(s[r--]);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.reverseOnlyLetters("ab-cd") << endl;
	cout << solution.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
	cout << solution.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
}

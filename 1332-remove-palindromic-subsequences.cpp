#include <iostream>

using namespace std;

class Solution {
public:
	int removePalindromeSub(string s) {
		int l = 0, r = s.length() - 1;
		while (l < r) {
			if (s[l] != s[r])
				return 2;
			++l;
			--r;
		}
		return 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.removePalindromeSub("ababa") << endl;
	cout << solution.removePalindromeSub("abb") << endl;
	cout << solution.removePalindromeSub("baab") << endl;
}

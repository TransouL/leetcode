#include <iostream>
using namespace std;

class Solution {
	bool isPalindrome(string &s, int i, int j) {
		while (i < j && s[i] == s[j])
			++i, --j;
		return i >= j;
	}

	bool check(string &a, string &b) {
		int i = 0, j = a.length() - 1;
		while (i < j && a[i] == b[j])
			++i, --j;
		return isPalindrome(a, i, j) || isPalindrome(b, i, j);
	}

public:
	bool checkPalindromeFormation(string a, string b) {
		return check(a, b) || check(b, a);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.checkPalindromeFormation("x", "y") << endl;
	cout << solution.checkPalindromeFormation("abdef", "fecab") << endl;
	cout << solution.checkPalindromeFormation("ulacfd", "jizalu") << endl;
}
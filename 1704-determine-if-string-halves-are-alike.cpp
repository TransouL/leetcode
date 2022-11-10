#include <iostream>
using namespace std;

class Solution {
public:
	bool halvesAreAlike(string s) {
		int n = s.size(), cnt = 0;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
				s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				++cnt;
			}
		}
		for (int i = n / 2; i < n; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
				s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				--cnt;
			}
		}
		return cnt == 0;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.halvesAreAlike("book") << endl;
	cout << solution.halvesAreAlike("textbook") << endl;
}
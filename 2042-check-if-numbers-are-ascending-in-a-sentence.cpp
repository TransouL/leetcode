#include <iostream>
using namespace std;

class Solution {
public:
	bool areNumbersAscending(string s) {
		int prev = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			if (isdigit(s[i])) {
				int curr = 0;
				do {
					curr = curr * 10 + (s[i] - '0');
					++i;
				} while (i < n && s[i] != ' ');
				if (curr <= prev) {
					return false;
				}
				prev = curr;
			}
			else {
				do {
					++i;
				} while (i < n && s[i] != ' ');
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles") << endl;
	cout << solution.areNumbersAscending("hello world 5 x 5") << endl;
	cout << solution.areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s") << endl;
	cout << solution.areNumbersAscending("4 5 11 26") << endl;
}
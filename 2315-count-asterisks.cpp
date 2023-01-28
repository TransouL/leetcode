#include <iostream>
using namespace std;

class Solution {
public:
	int countAsterisks(string s) {
		int ans = 0;
		bool check = true;
		for (auto &ch : s) {
			if (ch == '|') {
				check = !check;
			} else if (check && ch == '*') {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countAsterisks("l|*e*et|c**o|*de|") << endl;
	cout << solution.countAsterisks("iamprogrammer") << endl;
	cout << solution.countAsterisks("yo|uar|e**|b|e***au|tifu|l") << endl;
}
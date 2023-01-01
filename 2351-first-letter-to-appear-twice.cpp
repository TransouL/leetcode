#include <iostream>
using namespace std;

class Solution {
public:
	char repeatedCharacter(string s) {
		bool flag[26] = { false };
		for (auto &ch : s) {
			int idx = ch - 'a';
			if (flag[idx]) {
				return ch;
			}
			else {
				flag[idx] = true;
			}
		}
		return 0;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.repeatedCharacter("abccbaacz") << endl;
	cout << solution.repeatedCharacter("abcdd") << endl;
}
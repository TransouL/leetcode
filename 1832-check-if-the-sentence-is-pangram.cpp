#include <iostream>
using namespace std;

class Solution {
public:
	bool checkIfPangram(string sentence) {
		bool stat[26] = {false};
		for (auto &ch : sentence) {
			stat[ch - 'a'] = true;
		}
		for (int i = 0; i < 26; i++) {
			if (!stat[i]) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;
	cout << solution.checkIfPangram("leetcode") << endl;
}
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string greatestLetter(string s) {
		int flag[26] = { 0 };
		for (auto &ch : s) {
			if (isupper(ch)) {
				flag[ch - 'A'] |= 2;
			}
			else {
				flag[ch - 'a'] |= 1;
			}
		}
		for (int i = 25; i >= 0; --i){
			if (flag[i] == 3) {
				return string(1, ('A' + i));
			}
		}
		return "";
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.greatestLetter("lEeTcOdE") << endl;
	cout << solution.greatestLetter("arRAzFif") << endl;
	cout << solution.greatestLetter("AbCdEfGhIjK") << endl;
}
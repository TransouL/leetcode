#include <iostream>
using namespace std;

class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		int n = s1.size();
		int state = 0;
		char exp1, exp2;
		for (int i = 0; i < n; i++) {
			char c1 = s1[i], c2 = s2[i];
			if (c1 != c2) {
				if (state == 0) {
					exp1 = c2, exp2 = c1;
				}
				else if (state == 1) {
					if (c1 != exp1 || c2 != exp2) {
						return false;
					}
				}
				else {
					return false;
				}
				++state;
			}
		}
		return state != 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.areAlmostEqual("bank", "kanb") << endl;
	cout << solution.areAlmostEqual("attack", "defend") << endl;
	cout << solution.areAlmostEqual("kelb", "kelb") << endl;
	cout << solution.areAlmostEqual("abcd", "dcba") << endl;
	cout << solution.areAlmostEqual("aa", "ac") << endl;
}

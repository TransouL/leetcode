#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minimumSwap(string s1, string s2) {
		int xy = 0, yx = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == 'x' && s2[i] == 'y') {
				++xy;
			}
			else if (s1[i] == 'y' && s2[i] == 'x') {
				++yx;
			}
		}
		if ((xy + yx) & 1) {
			return -1;
		}
		return xy / 2 + yx / 2 + xy % 2 + yx % 2;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumSwap("xx", "yy") << endl;
	cout << solution.minimumSwap("xy", "yx") << endl;
	cout << solution.minimumSwap("xx", "xy") << endl;
	cout << solution.minimumSwap("xxyyxyxyxx", "xyyxyxxxyx") << endl;
}
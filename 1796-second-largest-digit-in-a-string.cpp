#include <iostream>
using namespace std;

class Solution {
public:
	int secondHighest(string s) {
		int max1 = -1, max2 = -1;
		for (auto &ch : s) {
			if (isdigit(ch)) {
				int t = ch - '0';
				if (t > max1) {
					max2 = max1;
					max1 = t;
				}
				else if (t != max1 && t > max2) {
					max2 = t;
				}
			}
		}
		return max2;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.secondHighest("dfa12321afd") << endl;
	cout << solution.secondHighest("abc1111") << endl;
}
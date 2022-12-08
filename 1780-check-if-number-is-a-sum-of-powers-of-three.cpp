#include <iostream>
using namespace std;

class Solution {
public:
	bool checkPowersOfThree(int n) {
		while (n) {
			if (n % 3 == 0 || n % 3 == 1) {
				n /= 3;
			}
			else {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.checkPowersOfThree(12) << endl;
	cout << solution.checkPowersOfThree(91) << endl;
	cout << solution.checkPowersOfThree(21) << endl;
}
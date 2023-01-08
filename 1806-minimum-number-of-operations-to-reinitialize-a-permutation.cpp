#include <iostream>
using namespace std;

class Solution {
public:
	int reinitializePermutation(int n) {
		if (n == 2) {
			return 1;
		}
		int step = 1, pow2 = 2;
		while (pow2 != 1) {
			++step;
			pow2 = pow2 * 2 % (n - 1);
		}
		return step;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.reinitializePermutation(2) << endl;
	cout << solution.reinitializePermutation(4) << endl;
	cout << solution.reinitializePermutation(6) << endl;
}
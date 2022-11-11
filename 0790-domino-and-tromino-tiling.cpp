#include <iostream>
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
	int numTilings(int n) {
		if (n < 3) {
			return n;
		}
		long long a1 = 1, b1 = 0, a2 = 2, b2 = 2;
		for (int i = 3; i <= n; i++) {
			long long tmpa = a2, tmpb = b2;
			a2 = (a2 + b2 + a1) % MOD;
			b2 = (a1 * 2 + b2) % MOD;
			a1 = tmpa, b1 = tmpb;
		}
		return a2;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numTilings(3) << endl;
	cout << solution.numTilings(1) << endl;
	cout << solution.numTilings(4) << endl; // 11
}
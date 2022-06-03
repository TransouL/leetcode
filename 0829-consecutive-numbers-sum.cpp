#include <iostream>
using namespace std;

class Solution {
	bool isKConsecitove(int n, int k) {
		if (k & 1 == 1) {
			return n % k == 0;
		}
		else {
			return n % k != 0 && 2 * n % k == 0;
		}
	}
public:
	int consecutiveNumbersSum(int n) {
		int ans = 0;
		for (int k = 1; k * (k+1) <= n * 2 ; k++) {
			if (isKConsecitove(n, k)) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.consecutiveNumbersSum(5) << endl;
	cout << solution.consecutiveNumbersSum(9) << endl;
	cout << solution.consecutiveNumbersSum(15) << endl;
}

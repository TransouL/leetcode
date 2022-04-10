#include <iostream>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 10;
		int ans = 10, curr = 9;
		for (int i = 0; i <= n - 2; i++) {
			curr *= 9 - i;
			ans += curr;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countNumbersWithUniqueDigits(2) << endl;
	cout << solution.countNumbersWithUniqueDigits(0) << endl;
	cout << solution.countNumbersWithUniqueDigits(8) << endl;
}

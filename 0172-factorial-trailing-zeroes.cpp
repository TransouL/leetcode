#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		for (int x = n / 5; x > 0; x /= 5) {
			ans += x;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.trailingZeroes(3) << endl;
	cout << solution.trailingZeroes(5) << endl;
	cout << solution.trailingZeroes(10000) << endl;
}

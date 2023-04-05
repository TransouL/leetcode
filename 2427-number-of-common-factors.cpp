#include <iostream>
using namespace std;

class Solution {
	int gcd(int a, int b) {
		return b != 0 ? gcd(b, a % b) : a;
	}

public:
	int commonFactors(int a, int b) {
		int g = gcd(a, b);
		if (g == 1)
			return 1;
		int ans = 2;
		for (int i = 2; i < g; i++){
			if (a % i == 0 && b % i == 0) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.commonFactors(12, 6) << endl;
	cout << solution.commonFactors(25, 30) << endl;
}
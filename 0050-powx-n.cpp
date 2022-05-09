#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		bool minus = false;
		long long y = n;
		if (n < 0){
			y = -y;
			minus = true;
		}
		double ret = 1.0;
		while (y) {
			if (y & 1)
				ret *= x;
			x *= x;
			y >>= 1;
		}
		return minus ? (1.0 / ret) : ret;
	}
};


int main(void){
	Solution solution = Solution();
	cout << solution.myPow(2.00000, 10) << endl;
	cout << solution.myPow(2.10000, 3) << endl;
	cout << solution.myPow(2.00000, -2) << endl;
	cout << solution.myPow(1.00000, -2147483647-1) << endl;
}
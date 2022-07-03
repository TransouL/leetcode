#include <iostream>
using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		int x = n, cnt = 1;
		for (; x >= 10 && x / 10 % 10 >= x % 10; x /= 10) {
			++cnt;
		}
		x /= 10;
		if (x == 0) {
			return -1;
		}

		int targetDigit = x % 10;
		int x2 = n, cnt2 = 0;
		for (; x2 % 10 <= targetDigit; x2 /= 10) {
			++cnt2;
		} 
		x += x2 % 10 - targetDigit;

		for (int i = 0; i < cnt; ++i, n /= 10) {
			int d = i == cnt2 ? targetDigit : n % 10;
			if (x > INT_MAX / 10 || x == INT_MAX / 10 && d > 7) {
				return -1;
			}
			x = x * 10 + d;
		}
		return x;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.nextGreaterElement(12) << endl;
	cout << solution.nextGreaterElement(21) << endl;
}
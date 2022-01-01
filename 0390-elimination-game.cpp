#include <iostream>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		int a1 = 1, an = n;
		int round = 0, cnt = n, step = 1;
		while (cnt > 1) {
			if (round % 2 == 0) {
				a1 = a1 + step;
				an = (cnt % 2 == 0) ? an : an - step;
			}
			else {
				a1 = (cnt % 2 == 0) ? a1 : a1 + step;
				an = an - step;
			}
			++round;
			cnt >>= 1;
			step <<= 1;
		}
		return a1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.lastRemaining(9) << endl;
}

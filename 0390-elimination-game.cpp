#include <iostream>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		int a1 = 1, cnt = n, step = 1;
		bool forword = true;
		while (cnt > 1) {
			if (forword) {
				a1 = a1 + step;
			}
			else {
				a1 = ((cnt & 1) == 0) ? a1 : a1 + step;
			}
			forword = !forword;
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

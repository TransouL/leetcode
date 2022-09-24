#include <iostream>
using namespace std;

class Solution {
public:
	int rotatedDigits(int n) {
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			int num = i;
			bool isRotated = true;
			bool isChanged = false;
			while (num > 0) {
				int currBit = num % 10;
				if (currBit == 2 || currBit == 5 || currBit == 6 || currBit == 9) {
					isChanged = true;
					num /= 10;
				}
				else if (currBit == 0 || currBit == 1 || currBit == 8) {
					num /= 10;
				}
				else {
					isRotated = false;
					break;
				}
			}
			if (isRotated && isChanged) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.rotatedDigits(10) << endl;
	cout << solution.rotatedDigits(9999) << endl;
	cout << solution.rotatedDigits(857) << endl; // 247
}
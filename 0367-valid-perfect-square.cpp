#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 1, right = max(1, min(num / 2, 46340));
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int tmpSquare = mid * mid;
			if (tmpSquare == num){
				return true;
			}
			else if (tmpSquare < num){
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return false;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isPerfectSquare(16) << endl;
	cout << solution.isPerfectSquare(14) << endl;
	cout << solution.isPerfectSquare(2147395600) << endl;
	cout << solution.isPerfectSquare((2 << 31) - 1) << endl;
}
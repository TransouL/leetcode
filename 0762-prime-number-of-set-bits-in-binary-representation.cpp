#include <iostream>

using namespace std;
//#define __builtin_popcount __popcnt

class Solution {
public:
	int countPrimeSetBits(int left, int right) {
		int leftBits = 0, rightBits = 0;
		int curr = left;
		while (curr) {
			curr >>= 1;
			++leftBits;
		}
		curr = right;
		while (curr) {
			curr >>= 1;
			++rightBits;
		}

		int ans = 0;
		if (rightBits - leftBits < 2) {
			for (int i = left; i <= right; i++) {
				if ((1 << __builtin_popcount(i)) & 665772) {
					++ans;
				}
			}
		}
		else {
			for (int i = 1 << (rightBits - 1); i <= right; i++) {
				if ((1 << __builtin_popcount(i)) & 665772) {
					++ans;
				}
			}
			for (int i = left; i <= (1 << leftBits) - 1; i++) {
				if ((1 << __builtin_popcount(i)) & 665772) {
					++ans;
				}
			}

			for (int first1 = leftBits + 1; first1 < rightBits; ++first1) {
				if (first1 >= 2) {
					ans += first1 - 1;
					if (first1 >= 3) {
						ans += (first1 - 1) * (first1 - 2) / 2;
						if (first1 >= 5) {
							ans += (first1 - 1) * (first1 - 2) * (first1 - 3) * (first1 - 4) / 24;
							if (first1 >= 7) {
								ans += (first1 - 1) * (first1 - 2) * (first1 - 3) * (first1 - 4)* (first1 - 5) * (first1 - 6) / 720;
								if (first1 >= 11) {
									ans += (first1 - 1) * (first1 - 2) * (first1 - 3) * (first1 - 4)* (first1 - 5) * (first1 - 6) * (first1 - 7) * (first1 - 8) * (first1 - 9) * (first1 - 10) / 3628800;
									if (first1 == 13) {
										ans += 1;
									}
								}
							}
						}
					}
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countPrimeSetBits(6, 10) << endl;
	cout << solution.countPrimeSetBits(10, 15) << endl;
	cout << solution.countPrimeSetBits(5, 31) << endl;
	cout << solution.countPrimeSetBits(842, 888) << endl;
	cout << solution.countPrimeSetBits(1, 1000000) << endl; // 这个思路在这个case是错的，因为上面按照题目限定的范围，first1只处理到13
}

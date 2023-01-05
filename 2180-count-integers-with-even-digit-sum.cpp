#include <iostream>
using namespace std;

class Solution {
public:
	int countEven(int num) {
		int ans = (num / 10) * 5 - 1;
		for (int i = num; i >= num / 10 * 10; --i) {
			int tmp = i, sum_ = 0;
			while (tmp) {
				sum_ += tmp % 10;
				tmp = tmp / 10;
			}
			if ((sum_ & 1) == 0) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countEven(4) << endl;
	cout << solution.countEven(30) << endl;
	cout << solution.countEven(108) << endl;
}
#include <iostream>
using namespace std;

class Solution {
	long check(long n, long index, long m) {
		long res = 0;
		if (m <= index) {
			res += (1 + m)*m / 2 + (index - m + 1);
		}
		else {
			res += (m - index + m) * (index + 1) / 2;
		}
		int right = n - 1 - index;
		if (m <= right) {
			res += (1 + m - 1)*(m - 1) / 2 + (right - m + 1);
		}
		else {
			res += (m - right + m - 1) * right / 2;
		}
		return res;
	}
public:
	int maxValue(int n, int index, int maxSum) {
		int l = 1, r = maxSum;
		while (l < r) {
			int m = (l + r + 1) / 2;
			long res = check(n, index, m);
			if (res == maxSum) {
				return m;
			}
			else if (res < maxSum) {
				l = m;
			}
			else {
				r = m - 1;
			}
		}
		return l;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxValue(4, 2, 6) << endl;
	cout << solution.maxValue(6, 1, 10) << endl;
	cout << solution.maxValue(6, 2, 931384943) << endl;
}
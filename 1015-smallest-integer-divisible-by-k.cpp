#include <iostream>
using namespace std;

class Solution {
public:
	int smallestRepunitDivByK(int k) {
		if (k % 2 == 0 || k % 5 == 0)
			return -1;
		int x = 1 % k;
		for (int i = 1; ; i++) {
			if (x == 0)
				return i;
			x = (x * 10 + 1) % k;
		}
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.smallestRepunitDivByK(1) << endl;
	cout << solution.smallestRepunitDivByK(2) << endl;
	cout << solution.smallestRepunitDivByK(3) << endl;
}
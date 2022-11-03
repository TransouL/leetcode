#include <iostream>
using namespace std;

class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		int coverStep = ceil((-1.0 + sqrt(1 + (long long)target * 8)) / 2.0);
		int pos = (coverStep + 1) * coverStep / 2;

		if ((pos - target) & 1) {
			if (coverStep & 1) {
				return coverStep + 2;
			}
			else {
				return coverStep + 1;
			}
		}
		else {
			return coverStep;
		}
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.reachNumber(2) << endl;
	cout << solution.reachNumber(3) << endl;
	cout << solution.reachNumber(25) << endl;
	cout << solution.reachNumber(1000000000) << endl;
	cout << solution.reachNumber(-1) << endl;
}

#include <iostream>
using namespace std;

class Solution {
public:
	int numberOfCuts(int n) {
		if (n == 1)
			return 0;
		return n & 1 ? n : n / 2;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numberOfCuts(4) << endl;
	cout << solution.numberOfCuts(3) << endl;
	cout << solution.numberOfCuts(1) << endl; // 0
}
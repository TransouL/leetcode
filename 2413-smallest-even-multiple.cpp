#include <iostream>
using namespace std;

class Solution {
public:
	int smallestEvenMultiple(int n) {
		return n & 1 ? n * 2 : n;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.smallestEvenMultiple(5) << endl;
	cout << solution.smallestEvenMultiple(6) << endl;
}
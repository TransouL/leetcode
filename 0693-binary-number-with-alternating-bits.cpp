#include <iostream>

using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		long a = n ^ (n >> 1);
		return (a & (a + 1)) == 0;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.hasAlternatingBits(5) << endl;
	cout << solution.hasAlternatingBits(7) << endl;
	cout << solution.hasAlternatingBits(11) << endl;
	cout << solution.hasAlternatingBits(2 ^ 31 - 1) << endl;
	cout << solution.hasAlternatingBits(1431655765) << endl;
}

#include <iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.addDigits(38) << endl;
	cout << solution.addDigits(0) << endl;
}

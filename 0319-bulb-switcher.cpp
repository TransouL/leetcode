#include <iostream>

using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n + 0.5);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.bulbSwitch(3) << endl;
	cout << solution.bulbSwitch(0) << endl;
	cout << solution.bulbSwitch(1) << endl;
	cout << solution.bulbSwitch(1e9) << endl;
}
#include <iostream>

using namespace std;

class Solution {
public:
	int totalMoney(int n) {
		int weeks = n / 7, days = n % 7;
		// return ((1 + 7) * 7 / 2 + (weeks - 1 + 1 + weeks - 1 + 7) / 2 * 7) * weeks / 2 + (weeks + 1 + weeks + 1 + days - 1) * days / 2;
		return ((weeks * 7 + 49) * weeks + (weeks * 2 + days + 1) * days) / 2;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.totalMoney(4) << endl;
	cout << solution.totalMoney(10) << endl;
	cout << solution.totalMoney(20) << endl;
	cout << solution.totalMoney(1000) << endl;
}

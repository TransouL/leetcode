#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string printBin(double num) {
		string ans = "0.";
		while (num != 0 && ans.size() <= 32) {
			num *= 2;
			int digit = num;
			ans += ('0' + digit);
			num -= digit;
		}
		return ans.size() <= 32 ? ans : "ERROR";
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.printBin(0.625) << endl;
	cout << solution.printBin(0.1) << endl;
}
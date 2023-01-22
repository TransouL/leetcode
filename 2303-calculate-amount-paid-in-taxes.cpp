#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double calculateTax(vector<vector<int>>& brackets, int income) {
		double ans = 0.0;
		int pre = 0;
		for (auto &b : brackets) {
			if (b[0] < income) {
				ans += (b[0] - pre) * b[1] / 100.0;
				pre = b[0];
			}
			else {
				ans += (income - pre) * b[1] / 100.0;
				break;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.calculateTax(vector<vector<int>> {{3, 50}, { 7, 10 }, {12, 25}}, 10) << endl;
}
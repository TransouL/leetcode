#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int gcd(int a, int b) {
		return b != 0 ? gcd(b, a % b) : a;
	}

public:
	bool isGoodArray(vector<int>& nums) {
		int divisor = nums[0];
		for (auto &num : nums) {
			divisor = gcd(divisor, num);
			if (divisor == 1) {
				return true;
			}
		}
		return false;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.isGoodArray(vector<int> {12, 5, 7, 23}) << endl;
	cout << solution.isGoodArray(vector<int> {29, 6, 10}) << endl;
	cout << solution.isGoodArray(vector<int> {3, 6}) << endl;
}
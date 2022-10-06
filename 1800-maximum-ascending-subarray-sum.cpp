#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int ans = 0, curr = 0, prev = 0;
		for (auto &num : nums) {
			if (num > prev) {
				curr += num;
			}
			else {
				ans = max(ans, curr);
				curr = num;
			}
			prev = num;
		}
		return max(ans, curr);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxAscendingSum(vector<int> {10, 20, 30, 5, 10, 50}) << endl;
	cout << solution.maxAscendingSum(vector<int> {10, 20, 30, 40, 50}) << endl;
	cout << solution.maxAscendingSum(vector<int> {12, 17, 15, 13, 10, 11, 12}) << endl;
	cout << solution.maxAscendingSum(vector<int> {100, 10, 1}) << endl;
}

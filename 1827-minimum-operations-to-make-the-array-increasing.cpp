#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums) {
		int n = nums.size();
		int curr = nums[0] - 1;
		int ans = 0;
		for (auto &num : nums) {
			if (num <= curr) {
				ans += (curr - num + 1);
				curr += 1;
			}
			else {
				curr = num;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minOperations(vector<int> {1, 1, 1}) << endl;
	cout << solution.minOperations(vector<int> {1, 5, 2, 4, 1}) << endl;
	cout << solution.minOperations(vector<int> {8}) << endl;
}
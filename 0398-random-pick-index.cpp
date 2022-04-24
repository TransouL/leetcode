#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<int> &nums;
public:
	Solution(vector<int> &nums) : nums(nums) {}

	int pick(int target) {
		int ans;
		for (int i = 0, cnt = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				++cnt;
				int a = rand();
				if (a % cnt == 0) {
					ans = i;
				}
			}
		}
		return ans;
	}
};

int main(void){
	vector<int> nums = { 1, 2, 3, 3, 3 };
	Solution solution = Solution(nums);
	for (size_t i = 0; i < 10; i++)
		cout << solution.pick(3) << endl;
	cout << solution.pick(1) << endl;
}

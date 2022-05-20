#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		if (nums[0] == nums[1])
			return nums[0];
		if (nums[2] == nums[0] || nums[2] == nums[1])
			return nums[2];
		if (nums[3] == nums[0] || nums[3] == nums[1] || nums[3] == nums[2])
			return nums[3];
		for (int i = 4; i < nums.size(); i+=2) {
			if (nums[i] == nums[i + 1])
				return nums[i];
		}
		return 0;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.repeatedNTimes(vector<int> { 1, 2, 3, 3 }) << endl;
	cout << solution.repeatedNTimes(vector<int> { 2, 1, 2, 5, 3, 2 }) << endl;
	cout << solution.repeatedNTimes(vector<int> { 5, 1, 5, 2, 5, 3, 5, 4 }) << endl;
}

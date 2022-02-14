#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int check(int x, vector<int>& nums) {
		if (x % 2 == 0) {
			if (nums[x] == nums[x + 1]) {
				return -1;
			}
			else if (nums[x] == nums[x - 1]) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (nums[x] == nums[x + 1]) {
				return 1;
			}
			else if (nums[x] == nums[x - 1]) {
				return -1;
			}
			else {
				return 0;
			}
		}
	}

public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		if (n == 1 || nums[0] != nums[1]){
			return nums[0];
		}
		if (nums[n- 1] != nums[n - 2]){
			return nums[n - 1];
		}

		int l = 1, r = n - 2;
		while (l < r) {
			int mid = (l + r) / 2;
			int checkRes = check(mid, nums);
			if (checkRes == 0) {
				return nums[mid];
			}
			else if (checkRes < 0) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return nums[l];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.singleNonDuplicate(vector<int> { 1, 1, 2, 3, 3, 4, 4, 8, 8 }) << endl;
	cout << solution.singleNonDuplicate(vector<int> { 3, 3, 7, 7, 10, 11, 11 }) << endl;
}

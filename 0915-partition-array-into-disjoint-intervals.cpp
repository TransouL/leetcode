#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int partitionDisjoint(vector<int>& nums) {
		int n = nums.size();
		vector<int> minRight(n);
		minRight[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0 ; i--) {
			minRight[i] = min(nums[i], minRight[i + 1]);
		}
		int maxLeft = 0;
		for (int i = 0; i < n - 1; i++) {
			maxLeft = max(maxLeft, nums[i]);
			if (maxLeft <= minRight[i + 1]) {
				return i + 1;
			}
		}
		return n - 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.partitionDisjoint(vector<int> {5, 0, 3, 8, 6}) << endl;
	cout << solution.partitionDisjoint(vector<int> {1, 1, 1, 0, 6, 12}) << endl;
}

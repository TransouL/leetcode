#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), left = 0, right = nums.back() - nums.front();
		while (left <= right) {
			int mid = (left + right) / 2;
			int cnt = 0;
			for (int i = 0, j = 0; j < n; j++) {
				while (nums[j] - nums[i] > mid) {
					++i;
				}
				cnt += j - i;
			}
			if (cnt >= k) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.smallestDistancePair(vector<int> {1, 3, 1}, 1) << endl;
	cout << solution.smallestDistancePair(vector<int> {1, 1, 1}, 2) << endl;
	cout << solution.smallestDistancePair(vector<int> {1, 6, 1}, 3) << endl;
}
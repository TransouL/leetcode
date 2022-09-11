#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int specialArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int l = 0, r = n;
		auto b = nums.begin(), e = nums.end();
		while (l <= r) {
			int mid = (l + r) / 2;
			auto idx = lower_bound(b, e, mid);
			if (nums.end() - idx == mid) {
				return mid;
			}
			else if (nums.end() - idx < mid) {
				r = mid - 1;
				e = idx;
			}
			else {
				l = mid + 1;
				b = idx;
			}
		}
		return -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.specialArray(vector<int> {3, 5}) << endl;
	cout << solution.specialArray(vector<int> {0, 0}) << endl;
	cout << solution.specialArray(vector<int> {0, 4, 3, 0, 4}) << endl;
	cout << solution.specialArray(vector<int> {3, 6, 7, 7, 0}) << endl;
}

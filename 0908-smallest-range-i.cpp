#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& nums, int k) {
		int min_ = 10000, max_ = 1;
		for (auto &num : nums){
			min_ = min(min_, num);
			max_ = max(max_, num);
		}
		return max(0, max_ - min_ - k * 2);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.smallestRangeI(vector<int> {1}, 0) << endl;
	cout << solution.smallestRangeI(vector<int> {0, 10}, 2) << endl;
	cout << solution.smallestRangeI(vector<int> {1, 3, 6}, 3) << endl;
}

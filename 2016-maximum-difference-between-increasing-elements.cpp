#include <iostream>
#include <vector>

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int maximumDifference(vector<int>& nums) {
		int min_ = nums[0], ans = -1;
		for (auto &num : nums) {
			if (min_ < num) {
				ans = max(ans, num - min_);
			}
			else {
				min_ = num;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maximumDifference(vector<int> {7, 1, 5, 4}) << endl;
	cout << solution.maximumDifference(vector<int> {9, 4, 3, 2}) << endl;
	cout << solution.maximumDifference(vector<int> {1, 5, 2, 10}) << endl;
}

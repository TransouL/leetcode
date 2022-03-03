#include <iostream>
#include <vector>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long ans = 0;
		for (size_t start = 0; start < nums.size(); start++) {
			int min_ = nums[start], max_ = nums[start];
			for (size_t end = start + 1; end < nums.size(); end++) {
				min_ = min(min_, nums[end]);
				max_ = max(max_, nums[end]);
				ans = ans + max_ - min_;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.subArrayRanges(vector<int> {1, 2, 3}) << endl;
	cout << solution.subArrayRanges(vector<int> {1, 3, 3}) << endl;
	cout << solution.subArrayRanges(vector<int> {4, -2, -3, 4, 1}) << endl;
}

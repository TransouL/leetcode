#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) {
			return to_string(nums[0]);
		}
		else if (n == 2) {
			return to_string(nums[0]) + "/" + to_string(nums[1]);
		}

		string ans = to_string(nums[0]) + "/(";
		for (int i = 1; i < n - 1; i++) {
			ans.append(to_string(nums[i])).append("/");
		}
		ans.append(to_string(nums[n - 1])).append(")");
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.optimalDivision(vector<int> {1000, 100, 10, 2}) << endl;
	cout << solution.optimalDivision(vector<int> {2}) << endl;
	cout << solution.optimalDivision(vector<int> {4, 2}) << endl;
}

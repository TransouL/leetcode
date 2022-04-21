#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxRotateFunction(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) {
			return 0;
		}

		int ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			ans += i * nums[i];
		}

		int curr = ans;
		for (int i = n - 1; i > 0; --i) {
			curr += sum - nums[i] * n;
			ans = max(ans, curr);
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxRotateFunction(vector<int> {4, 3, 2, 6}) << endl;
	cout << solution.maxRotateFunction(vector<int> {100}) << endl;
}

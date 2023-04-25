#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 0; i < n; i++) {
			s[i + 1] = s[i] + nums[i];
		}
		int ans = 0, maxSumA = 0, maxSumB = 0;
		for (int i = firstLen + secondLen; i <= n; i++) {
			maxSumA = max(maxSumA, s[i - secondLen] - s[i - secondLen - firstLen]);
			maxSumB = max(maxSumB, s[i - firstLen] - s[i - firstLen - secondLen]);
			ans = max(ans, max(maxSumA + s[i] - s[i - secondLen],
				maxSumB + s[i] - s[i - firstLen]));
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxSumTwoNoOverlap(vector<int>{0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2) << endl;
	cout << solution.maxSumTwoNoOverlap(vector<int>{3, 8, 1, 3, 2, 1, 8, 9, 0}, 3, 2) << endl;
	cout << solution.maxSumTwoNoOverlap(vector<int>{2, 1, 5, 6, 0, 9, 5, 0, 3, 8}, 4, 3) << endl;
}
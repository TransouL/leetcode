#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSwap(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int prev1 = nums1[0], prev2 = nums2[0], ans = 0, curr = 0, done = 0;
		for (int i = 1; i < n; i++) {
			if (nums1[i] > prev1 && nums2[i] > prev2 && nums1[i] > prev2 && nums2[i] > prev1) {
				ans += min(curr, i - done - curr);
				curr = 0, done = i, prev1 = nums1[i], prev2 = nums2[i];
			} 
			else if (nums1[i] > prev1 && nums2[i] > prev2) {
				prev1 = nums1[i];
				prev2 = nums2[i];
			}
			else {
				curr += 1;
				prev1 = nums2[i];
				prev2 = nums1[i];
			}
		}
		ans += min(curr, n - done - curr);
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minSwap(vector<int>{1, 3, 5, 4}, vector<int>{1, 2, 3, 7}) << endl;
	cout << solution.minSwap(vector<int>{0, 3, 5, 8, 9}, vector<int>{2, 1, 4, 6, 9}) << endl;
	cout << solution.minSwap(vector<int>{0, 4, 4, 5, 9}, vector<int>{0, 1, 6, 8, 10}) << endl; // 1
}

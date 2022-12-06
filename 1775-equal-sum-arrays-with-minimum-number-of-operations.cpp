#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums1, vector<int>& nums2) {
		vector<int> cnt1(7, 0), cnt2(7, 0);
		int tot1 = 0, tot2 = 0;
		for (auto &num : nums1) {
			++cnt1[num];
			tot1 += num;
		}
		for (auto &num : nums2) {
			++cnt2[num];
			tot2 += num;
		}
		if (tot1 == tot2){
			return 0;
		}
		int diff = tot1 - tot2;
		if (tot1 < tot2) {
			diff = tot2 - tot1;
			vector<int> tmp = cnt1;
			cnt1 = cnt2;
			cnt2 = tmp;
		}

		int ans = 0;
		while (diff > 0){
			int change = 5;
			for (; change >= 1; --change) {
				if (cnt1[change + 1]) {
					--cnt1[change + 1];
					diff -= change;
					++ans;
					break;
				}
				if (cnt2[6 - change]) {
					--cnt2[6 - change];
					diff -= change;
					++ans;
					break;
				}
			}
			if (change == 0) {
				return -1;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minOperations(vector<int>{1, 2, 3, 4, 5, 6}, vector<int>{1, 1, 2, 2, 2, 2}) << endl;
	cout << solution.minOperations(vector<int>{1, 1, 1, 1, 1, 1, 1}, vector<int>{6}) << endl;
	cout << solution.minOperations(vector<int>{6, 6}, vector<int>{1}) << endl;
	cout << solution.minOperations(vector<int>{3, 3, 2, 4, 2, 6, 2}, vector<int>{6, 2, 6, 6, 1, 1, 4, 6, 4, 6, 2, 5, 4, 2, 1}) << endl; // 8
}
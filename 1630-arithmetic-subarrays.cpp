#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		int n = l.size();
		vector<bool> ans;
		for (int i = 0; i < n; ++i) {
			int left = l[i], right = r[i];
			int minv = *min_element(nums.begin() + left, nums.begin() + right + 1);
			int maxv = *max_element(nums.begin() + left, nums.begin() + right + 1);

			if (minv == maxv) {
				ans.push_back(true);
				continue;
			}
			if ((maxv - minv) % (right - left) != 0) {
				ans.push_back(false);
				continue;
			}

			int d = (maxv - minv) / (right - left);
			bool flag = true;
			vector<int> seen(right - left + 1);
			for (int j = left; j <= right; ++j) {
				if ((nums[j] - minv) % d != 0) {
					flag = false;
					break;
				}
				int t = (nums[j] - minv) / d;
				if (seen[t]) {
					flag = false;
					break;
				}
				seen[t] = true;
			}
			ans.push_back(flag);
		}
		return ans;
	}
};

void printVector(const vector<bool> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.checkArithmeticSubarrays(vector<int>{4, 6, 5, 9, 3, 7}, vector<int>{0, 0, 2}, vector<int>{2, 3, 5}));
	printVector(solution.checkArithmeticSubarrays(vector<int>{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10}, vector<int>{0, 1, 6, 4, 8, 7}, vector<int>{4, 4, 9, 7, 9, 10}));
}
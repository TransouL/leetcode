#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int ans;
	void dfs(vector<int>& nums, int idx, int curr, int maxOr) {
		int n = nums.size();
		if (curr == maxOr) {
			ans += (pow(2, n - idx));
			return;
		}
		if (idx < n) {
			dfs(nums, idx + 1, curr | nums[idx], maxOr);
			dfs(nums, idx + 1, curr, maxOr);
		}
	}
public:
	int countMaxOrSubsets(vector<int>& nums) {
		ans = 0;
		int uniqueOr = 0;
		for (int mask = 1; mask < 100000; mask <<= 1) {
			if (uniqueOr & mask) {
				continue;
			}
			int count = 0;
			vector<int>::iterator first;
			for (auto it = nums.begin(); it != nums.end(); ++it) {
				if (*it & mask) {
					++count;
					if (count == 1) {
						first = it;
					}
					else {
						break;
					}
				}
			}
			if (count == 1) {
				uniqueOr |= *first;
				nums.erase(first);
			}
			else if (count == 0) {
				break;
			}
		}

		int maxOr = uniqueOr;
		for (auto &num : nums) {
			maxOr |= num;
		}

		dfs(nums, 0, uniqueOr, maxOr);

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countMaxOrSubsets(vector<int> {3, 1}) << endl;
	cout << solution.countMaxOrSubsets(vector<int> {2, 2, 2}) << endl;
	cout << solution.countMaxOrSubsets(vector<int> {3, 2, 1, 5}) << endl;
	cout << solution.countMaxOrSubsets(vector<int> {75115, 4464, 69031, 81186}) << endl; // 2
}

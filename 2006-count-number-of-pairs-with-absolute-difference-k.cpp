#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		unordered_map<int, int> cnt;
		int ans = 0;
		for (auto &num : nums) {
			if (cnt.count(num)){
				ans += cnt[num];
			}
			if (num + k <= 100) {
				++cnt[num + k];
			}
			if (num - k >= 1) {
				++cnt[num - k];
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countKDifference(vector<int> { 1, 2, 2, 1 }, 1) << endl;
	cout << solution.countKDifference(vector<int> { 1, 3 }, 3) << endl;
	cout << solution.countKDifference(vector<int> { 3, 2, 1, 5, 4 }, 2) << endl;
}

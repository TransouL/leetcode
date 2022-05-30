#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		if (n >= 3) {
			sort(nums.begin(), nums.end());
			int a = 0;
			for (; a < n - 2; a++) {
				if (nums[a] == 0) {
					break;
				}
				if (a > 0 && nums[a] == nums[a - 1]) {
					continue;
				}
				int target = -nums[a];
				int c = n - 1;
				for (int b = a + 1; b < n - 1; b++) {
					if (b > a + 1 && nums[b] == nums[b - 1]) {
						continue;
					}
					while (b < c && nums[b] + nums[c] > target) {
						--c;
					}
					if (b == c) {
						break;
					}
					if (nums[b] + nums[c] == target) {
						ans.push_back({ nums[a], nums[b], nums[c] });
					}
				}
			}
			if (nums[a] == 0 && a < n - 2 && nums[a + 1] == 0 && nums[a + 2] == 0) {
				ans.emplace_back(vector<int> { 0, 0, 0 });
			}
		}
		return ans;
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.threeSum(vector<int> { -1, 0, 1, 2, -1, -4 }));
	printVector(solution.threeSum(vector<int> {}));
	printVector(solution.threeSum(vector<int> { 0 }));
	printVector(solution.threeSum(vector<int> { 0, 0, 0}));
	printVector(solution.threeSum(vector<int> { -2, 0, 0, 2, 2})); // [[-2,0,2]]
}

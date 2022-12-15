#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minElements(vector<int>& nums, int limit, int goal) {
		long diff = goal;
		for (auto &num : nums) {
			diff -= num;
		}
		return diff == 0 ? 0 : (abs(diff) - 1) / limit + 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minElements(vector<int> {1, -1, 1}, 3, -4) << endl;
	cout << solution.minElements(vector<int> {1, -10, 9, 1}, 100, 0) << endl;
	cout << solution.minElements(vector<int> {1, 2, 3}, 300, 6) << endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int mostFrequentEven(vector<int>& nums) {
		unordered_map<int, int> stats;
		for (auto &num : nums) {
			if (!(num & 1)) {
				++stats[num];
			}
		}
		int ans = -1, cnt = 0;
		for (auto it = stats.begin(); it != stats.end(); ++it) {
			int key = it->first, value = it->second;
			if (value > cnt) {
				ans = key;
				cnt = value;
			}
			else if (value == cnt && key < ans) {
				ans = key;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.mostFrequentEven(vector<int> {0, 1, 2, 2, 4, 4, 1}) << endl;
	cout << solution.mostFrequentEven(vector<int> {4, 4, 4, 9, 2, 4}) << endl;
	cout << solution.mostFrequentEven(vector<int> {29, 47, 21, 41, 13, 37, 25, 7}) << endl;
}
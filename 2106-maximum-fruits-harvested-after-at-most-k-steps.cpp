#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int left = 0, right = 0, n = fruits.size(), sum = 0, ans = 0;
		auto step = [&](int left, int right) -> int {
			if (fruits[right][0] <= startPos) {
				return startPos - fruits[left][0];
			}
			else if (fruits[left][0] >= startPos) {
				return fruits[right][0] - startPos;
			}
			else {
				return fruits[right][0] - fruits[left][0] + min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0]));
			}
		};

		while (right < n) {
			sum += fruits[right][1];
			while (left <= right && step(left, right) > k) {
				sum -= fruits[left][1];
				++left;
			}
			ans = max(ans, sum);
			++right;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxTotalFruits(vector<vector<int>>{{2, 8}, { 6, 3 }, { 8, 6 }}, 5, 4) << endl;
	cout << solution.maxTotalFruits(vector<vector<int>>{{0, 9}, { 4, 1 }, { 5, 7 }, { 6, 2 }, { 7, 4 }, {10, 9} }, 5, 4) << endl;
	cout << solution.maxTotalFruits(vector<vector<int>>{{0, 3}, { 6, 4 }, { 8, 5 }}, 3, 2) << endl;
}
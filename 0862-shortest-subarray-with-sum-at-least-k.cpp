#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long> preSumArr(n + 1);
		for (int i = 0; i < n; i++) {
			preSumArr[i + 1] = preSumArr[i] + nums[i];
		}
		int ans = n + 1;
		deque<int> qu;
		for (int i = 0; i <= n; i++) {
			long curSum = preSumArr[i];
			while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
				ans = min(ans, i - qu.front());
				qu.pop_front();
			}
			while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
				qu.pop_back();
			}
			qu.push_back(i);
		}
		return ans < n + 1 ? ans : -1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.shortestSubarray(vector<int>{1}, 1) << endl;
	cout << solution.shortestSubarray(vector<int>{1, 2}, 4) << endl;
	cout << solution.shortestSubarray(vector<int>{2, -1, 2}, 3) << endl;
	cout << solution.shortestSubarray(vector<int>{77, 19, 35, 10, -14}, 19) << endl; // 1
	cout << solution.shortestSubarray(vector<int>{84, -37, 32, 40, 95}, 167) << endl; // 3
	cout << solution.shortestSubarray(vector<int>{56, -21, 56, 35, -9}, 61) << endl; // 2
	cout << solution.shortestSubarray(vector<int>{-28, 81, -20, 28, -29}, 89) << endl; // 3
	cout << solution.shortestSubarray(vector<int>{39353, 64606, -23508, 5678, -17612, 40217, 15351, -12613, -37037, 64183, 68965, -19778, -41764, -21512, 17700, -23100, 77370, 64076, 53385, 30915, 18025, 17577, 10658, 77805, 56466, -2947, 29423, 50001, 31803, 9888, 71251, -6466, 77254, -30515, 2903, 76974, -49661, -10089, 66626, -7065, -46652, 84755, -37843, -5067, 67963, 92475, 15340, 15212, 54320, -5286}, 207007) << endl; // 4
}


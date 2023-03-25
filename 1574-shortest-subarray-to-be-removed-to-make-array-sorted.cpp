#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size(), right = n - 1;
		while (right && arr[right - 1] <= arr[right])
			--right;
		if (right == 0) return 0;
		int ans = right;
		for (int left = 0; left == 0 || arr[left - 1] <= arr[left] ; ++left) {
			while (right < n && arr[right] < arr[left])
				++right;
			ans = min(ans, right - left - 1);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.findLengthOfShortestSubarray(vector<int>{1, 2, 3, 10, 4, 2, 3, 5}) << endl;
	cout << solution.findLengthOfShortestSubarray(vector<int>{5, 4, 3, 2, 1}) << endl;
	cout << solution.findLengthOfShortestSubarray(vector<int>{1, 2, 3}) << endl;
	cout << solution.findLengthOfShortestSubarray(vector<int>{1}) << endl;
}
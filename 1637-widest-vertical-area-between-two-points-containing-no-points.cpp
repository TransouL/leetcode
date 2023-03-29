#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		vector<int> x;
		for (auto point : points) {
			x.push_back(point[0]);
		}
		
		sort(x.begin(), x.end());
		int ans = 0;
		for (int i = 1; i < x.size(); i++) {
			ans = max(ans, x[i] - x[i - 1]);
		}

		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxWidthOfVerticalArea(vector<vector<int>> {{8, 7}, { 9, 9 }, { 7, 4 }, { 9, 7 }}) << endl;
	cout << solution.maxWidthOfVerticalArea(vector<vector<int>> {{3, 1}, { 9, 0 }, { 1, 0 }, { 1, 4 }, { 5, 3 }, { 8, 8 }}) << endl;
	cout << solution.maxWidthOfVerticalArea(vector<vector<int>> {{1, 1}, { 1, 2 }, { 1, 3 }}) << endl;
}
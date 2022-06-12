#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> expected(heights);
		sort(expected.begin(), expected.end());
		int ans = 0;
		for (int i = 0; i < heights.size(); i++) {
			if (heights[i] != expected[i]) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.heightChecker(vector<int> {1, 1, 4, 2, 1, 3}) << endl;
	cout << solution.heightChecker(vector<int> {5, 1, 2, 3, 4}) << endl;
	cout << solution.heightChecker(vector<int> {1, 2, 3, 4, 5}) << endl;
}
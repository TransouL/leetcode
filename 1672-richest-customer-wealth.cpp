#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int ans = 0;
		for (auto &account : accounts) {
			int t = 0;
			for (auto &v : account) {
				t += v;
			}
			ans = max(ans, t);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maximumWealth(vector<vector<int>> {{1, 2, 3}, {3, 2, 1}}) << endl;
}

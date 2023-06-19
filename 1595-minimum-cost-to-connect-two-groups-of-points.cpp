#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int connectTwoGroups(vector<vector<int>>& cost) {
		int size1 = cost.size(), size2 = cost[0].size(), m = 1 << size2;
		vector<int> dp1(m, INT_MAX / 2), dp2(m);
		dp1[0] = 0;
		for (int i = 1; i <= size1; i++) {
			for (int s = 0; s < m; s++) {
				dp2[s] = INT_MAX / 2;
				for (int k = 0; k < size2; k++) {
					if ((s & (1 << k)) == 0)
						continue;
					dp2[s] = min(dp2[s], dp2[s ^ (1 << k)] + cost[i - 1][k]);
					dp2[s] = min(dp2[s], dp1[s] + cost[i - 1][k]);
					dp2[s] = min(dp2[s], dp1[s ^ (1 << k)] + cost[i - 1][k]);
				}
			}
			dp1.swap(dp2);
		}
		return dp1[m - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.connectTwoGroups(vector<vector<int>>{{15, 96}, { 36, 2 }}) << endl;
	cout << solution.connectTwoGroups(vector<vector<int>>{{1, 3, 5}, { 4, 1, 1 }, { 1, 5, 3 }}) << endl;
	cout << solution.connectTwoGroups(vector<vector<int>>{{2, 5, 1}, { 3, 4, 7 }, { 8, 1, 2 }, { 6, 2, 4 }, { 3, 8, 8 }}) << endl;
}
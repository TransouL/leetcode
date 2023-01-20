#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	static const int inf = 0x3f3f3f3f;
public:
	int minSideJumps(vector<int>& obstacles) {
		int n = obstacles.size() - 1;
		vector<int> d = { 1, 0, 1 };
		for (int i = 1; i <= n; i++) {
			int minCnt = inf;
			for (int j = 0; j < 3; j++) {
				if (j == obstacles[i] - 1) {
					d[j] = inf;
				}
				else {
					minCnt = min(minCnt, d[j]);
				}
			}
			for (int j = 0; j < 3; j++) {
				if (j != obstacles[i] - 1) {
					d[j] = min(d[j], minCnt + 1);
				}
			}
		}
		return min(min(d[0], d[1]), d[2]);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minSideJumps(vector<int> {0, 1, 2, 3, 0}) << endl;
	cout << solution.minSideJumps(vector<int> {0, 1, 1, 3, 3, 0}) << endl;
	cout << solution.minSideJumps(vector<int> {0, 2, 1, 0, 3, 0}) << endl;
}
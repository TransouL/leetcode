#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int ans = -1, curr = 10001;
		for (int i = 0; i < points.size(); i++) {
			if (points[i][0] == x || points[i][1] == y) {
				int tmp = abs(points[i][0] - x) + abs(points[i][1] - y);
				if (tmp < curr) {
					ans = i;
					curr = tmp;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.nearestValidPoint(3, 4, vector<vector<int>> {{1, 2}, { 3, 1 }, { 2, 4 }, { 2, 3 }, { 4, 4 }}) << endl;
	cout << solution.nearestValidPoint(3, 4, vector<vector<int>> {{ 3, 4 }}) << endl;
	cout << solution.nearestValidPoint(3, 4, vector<vector<int>> {{ 2, 3 }}) << endl;
}
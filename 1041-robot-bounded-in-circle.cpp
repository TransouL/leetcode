#include <iostream>
using namespace std;

class Solution {
public:
	bool isRobotBounded(string instructions) {
		int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }, d = 0, x = 0, y = 0;
		for (auto &ch : instructions) {
			if (ch == 'G') {
				x += dx[d];
				y += dy[d];
			}
			else if (ch == 'L') {
				d = (d + 3) % 4;
			}
			else {
				d = (d + 1) % 4;
			}
		}
		return d != 0 || (x == 0 && y == 0);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.isRobotBounded("GGLLGG") << endl;
	cout << solution.isRobotBounded("GG") << endl;
	cout << solution.isRobotBounded("GL") << endl;
}
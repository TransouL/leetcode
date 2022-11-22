#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countBalls(int lowLimit, int highLimit) {
		vector<int> cnt(46, 0);
		for (int i = lowLimit; i <= highLimit; i++) {
			int tmp = 0, curr = i;
			while (curr) {
				tmp += (curr % 10);
				curr /= 10;
			}
			++cnt[tmp];
		}
		int ans = 1;
		for (auto c : cnt) {
			ans = max(ans, c);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countBalls(1, 10) << endl;
	cout << solution.countBalls(5, 15) << endl;
	cout << solution.countBalls(19, 28) << endl;
	cout << solution.countBalls(1, 100000) << endl;
}
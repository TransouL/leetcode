#include <iostream>
using namespace std;

class Solution {
public:
	int minimumBoxes(int n) {
		int ans = 0, max_n = 0;
		for (int i = 1; max_n + ans + i <= n; i++) {
			ans += i;
			max_n += ans;
		}
		for (int j = 1; max_n < n; j++) {
			++ans;
			max_n += j;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumBoxes(3) << endl;
	cout << solution.minimumBoxes(4) << endl;
	cout << solution.minimumBoxes(10) << endl;
}
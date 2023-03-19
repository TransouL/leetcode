#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
	int numDupDigitsAtMostN(int n) {
		auto s = to_string(n);
		int m = s.length(), dp[10][1 << 10];
		memset(dp, -1, sizeof(dp));
		function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
			if (i == m)
				return is_num;
			if (!is_limit && is_num && dp[i][mask] != -1)
				return dp[i][mask];
			int res = 0;
			if (!is_num)
				res = f(i + 1, mask, false, false);
			int up = is_limit ? s[i] - '0' : 9;
			for (int d = 1 - is_num; d <= up; ++d) 
				if ((mask >> d & 1) == 0)
					res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
			if (!is_limit && is_num)
				dp[i][mask] = res;
			return res;
		};
		return n - f(0, 0, true, false);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numDupDigitsAtMostN(20) << endl;
	cout << solution.numDupDigitsAtMostN(100) << endl;
	cout << solution.numDupDigitsAtMostN(1000) << endl;
}
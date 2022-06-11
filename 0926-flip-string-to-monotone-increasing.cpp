#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		int dp0 = 0, dp1 = 0;
		for (auto &c : s) {
			dp1 = min(dp0, dp1) + (c == '0');
			dp0 += (c == '1');
		}
		return min(dp0, dp1);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minFlipsMonoIncr("00110") << endl;
	cout << solution.minFlipsMonoIncr("010110") << endl;
	cout << solution.minFlipsMonoIncr("00011000") << endl;
}

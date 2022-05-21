#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
	unordered_map<int, bool> memo;

	bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal){
		if (!memo.count(usedNumbers)) {
			bool res = false;
			for (int i = 0; i < maxChoosableInteger; i++) {
				if (((usedNumbers >> i) & 1) == 0) {
					if (i + 1 + currentTotal >= desiredTotal) {
						res = true;
						break;
					}
					if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
						res = true;
						break;
					}
				}
			}
			memo[usedNumbers] = res;
		}
		return memo[usedNumbers];
	}
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		memo.clear();
		if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
			return false;
		}
		return dfs(maxChoosableInteger, 0, desiredTotal, 0);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canIWin(10, 11) << endl;
	cout << solution.canIWin(10, 0) << endl;
	cout << solution.canIWin(10, 1) << endl;
}

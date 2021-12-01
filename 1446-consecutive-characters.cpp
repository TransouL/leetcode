#include <iostream>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int maxPower(string s) {
		int ans = 1, lastCount = 1;
		char lastChar = 0;
		for (auto &ch : s) {
			if (ch == lastChar)
				++lastCount;
			else {
				ans = max(ans, lastCount);
				lastChar = ch;
				lastCount = 1;
			}
		}
		return max(ans, lastCount);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxPower("leetcode") << endl;
	cout << solution.maxPower("abbcccddddeeeeedcba") << endl;
	cout << solution.maxPower("triplepillooooow") << endl;
	cout << solution.maxPower("hooraaaaaaaaaaay") << endl;
	cout << solution.maxPower("hooraaaaaaaaaaa") << endl;
	cout << solution.maxPower("tourist") << endl;
}
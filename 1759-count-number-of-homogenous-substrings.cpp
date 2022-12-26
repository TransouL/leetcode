#include <iostream>
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
	int countHomogenous(string s) {
		long ans = 0L;
		long curr = 0;
		char last = 'A';
		s += "A";
		for (auto &ch : s) {
			if (ch == last) {
				++curr;
			}
			else {
				ans = (ans + (1 + curr) * curr / 2) % MOD;
				last = ch;
				curr = 1;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countHomogenous("abbcccaa") << endl;
	cout << solution.countHomogenous("xy") << endl;
	cout << solution.countHomogenous("zzzzz") << endl;
}
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
	int distinctSubseqII(string s) {
		vector<int> g(26, 0);
		int n = s.size(), total = 0;
		for (int i = 0; i < n; i++) {
			int oi = s[i] - 'a';
			int prev = g[oi];
			g[oi] = (total + 1) % MOD;
			total = ((total + g[oi] - prev) % MOD + MOD) % MOD;
		}
		return total;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.distinctSubseqII("abc") << endl;
	cout << solution.distinctSubseqII("aba") << endl;
	cout << solution.distinctSubseqII("aaa") << endl;
}

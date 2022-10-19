#include <iostream>
using namespace std;

class Solution {
public:
	int kthGrammar(int n, int k) {
		k--;
		int ans = 0;
		while (k > 0) {
			k &= k - 1;
			ans ^= 1;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.kthGrammar(1, 1) << endl;
	cout << solution.kthGrammar(2, 1) << endl;
	cout << solution.kthGrammar(2, 2) << endl;
}

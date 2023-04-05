#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string baseNeg2(int n) {
		if (n == 0 || n == 1) {
			return to_string(n);
		}
		string ans;
		while (n) {
			int rem = n & 1;
			ans.push_back('0' + rem);
			n -= rem;
			n /= -2;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.baseNeg2(2) << endl;
	cout << solution.baseNeg2(3) << endl;
	cout << solution.baseNeg2(4) << endl;
}
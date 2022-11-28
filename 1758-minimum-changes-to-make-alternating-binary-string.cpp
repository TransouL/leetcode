#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minOperations(string s) {
		int c = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			bool is1 = s[i] == '1';
			if (i & 1 ^ is1) {
				++c;
			}
		}
		return min(c, n - c);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minOperations("0100") << endl;
	cout << solution.minOperations("10") << endl;
	cout << solution.minOperations("1111") << endl;
}
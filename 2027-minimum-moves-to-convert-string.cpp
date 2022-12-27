#include <iostream>
using namespace std;

class Solution {
public:
	int minimumMoves(string s) {
		int ans = 0, i = 0;
		while (i < s.size()) {
			if (s[i] == 'X') {
				++ans;
				i += 3;
			}
			else {
				++i;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumMoves("XXX") << endl;
	cout << solution.minimumMoves("XXOX") << endl;
	cout << solution.minimumMoves("OOOO") << endl;
}
#include <iostream>
using namespace std;

class Solution {
public:
	int minimumLength(string s) {
		int l = 0, r = s.size() - 1;
		while (true) {
			if (l > r) {
				return 0;
			}
			if (l == r) {
				return 1;
			}
			char lc = s[l], rc = s[r];
			if (lc != rc) {
				break;
			}
			else {
				while (l <= r && s[l] == lc) {
					++l;
				}
				while (r >= l && s[r] == rc) {
					--r;
				}
			}
		}
		return r - l + 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumLength("ca") << endl;
	cout << solution.minimumLength("cabaabac") << endl;
	cout << solution.minimumLength("aabccabba") << endl;
	cout << solution.minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb") << endl; // 1
	cout << solution.minimumLength("bbbbbbbbbbbbbbbbbbb") << endl;
}
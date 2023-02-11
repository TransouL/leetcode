#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string alphabetBoardPath(string target) {
		int r = 0, c = 0;
		string ans = "";
		for (auto &ch : target) {
			int idx = ch - 'a';
			int nr = idx / 5, nc = idx % 5;
			int diffr = nr - r, diffc = nc - c;
			if (ch != 'z') {
				if (diffr > 0) {
					ans.append(diffr, 'D');
				}
				else {
					ans.append(-diffr, 'U');
				}
			}
			if (diffc > 0) {
				ans.append(diffc, 'R');
			}
			else {
				ans.append(-diffc, 'L');
			}
			if (ch == 'z') {
				if (diffr > 0) {
					ans.append(diffr, 'D');
				}
				else {
					ans.append(-diffr, 'U');
				}
			}
			ans += '!';
			r = nr, c = nc;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.alphabetBoardPath("leet") << endl;
	cout << solution.alphabetBoardPath("code") << endl;
}
#include <iostream>
using namespace std;

class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		char PREVIOUS['s'];
		const string croak = "croakc";
		for (int i = 1; i < croak.length(); i++) {
			PREVIOUS[croak[i]] = croak[i - 1];
		}
		int cnt['s']{};
		for (auto &ch : croakOfFrogs) {
			char pre = PREVIOUS[ch];
			if (cnt[pre])
				--cnt[pre];
			else if (ch != 'c')
				return -1;
			++cnt[ch];
		}
		if (cnt['c'] || cnt['r'] || cnt['o'] || cnt['a'])
			return -1;
		return cnt['k'];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minNumberOfFrogs("croakcroak") << endl;
	cout << solution.minNumberOfFrogs("crcoakroak") << endl;
	cout << solution.minNumberOfFrogs("croakcrook") << endl;
}
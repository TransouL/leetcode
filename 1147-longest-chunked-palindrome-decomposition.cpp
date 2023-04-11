#include <iostream>
using namespace std;

class Solution {
public:
	int longestDecomposition(string text) {
		int ans = 0;
		while (!text.empty()) {
			int i = 1, n = text.length();
			while (i <= n / 2 && text.substr(0, i) != text.substr(n - i)) {
				++i;
			}
			if (i > n / 2) {
				++ans;
				break;
			}
			ans += 2;
			text = text.substr(i, n - i * 2);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
	cout << solution.longestDecomposition("merchant") << endl;
	cout << solution.longestDecomposition("antaprezatepzapreanta") << endl;
}
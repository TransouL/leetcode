#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool queryString(string s, int n) {
		unordered_set<int> seen;
		for (int i = 0, m = s.length(); i < m; i++) {
			int x = s[i] - '0';
			if (x == 0)
				continue;
			for (int j = i + 1; x <= n; j++) {
				seen.insert(x);
				if (j == m)
					break;
				x = (x << 1) | (s[j] - '0');
			}
		}
		return seen.size() == n;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.queryString("0110", 3) << endl;
	cout << solution.queryString("0110", 4) << endl;
}
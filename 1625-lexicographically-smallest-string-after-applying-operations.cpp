#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x % y);
	}
public:
	string findLexSmallestString(string s, int a, int b) {
		int n = s.size();
		string ans = s;
		string t = s + s;
		int ga = gcd(10, a), gb = gcd(n, b);

		auto add = [&](string &p, int pos) {
			int lo = p[pos] - '0', added = 0;
			for (int i = ga; i < 10; i += ga) {
				int c = (p[pos] - '0' + i) % 10;
				if (c < lo) {
					lo = c;
					added = i;
				}
			}
			if (added)
				for (int i = pos; i < n; i += 2)
					p[i] = '0' + (p[i] - '0' + added) % 10;
		};

		for (int i = 0; i < n; i += gb) {
			string p = t.substr(i, n);
			add(p, 1);
			if (gb % 2)
				add(p, 0);
			ans = min(ans, p);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.findLexSmallestString("5525", 9, 2) << endl;
	cout << solution.findLexSmallestString("74", 5, 1) << endl;
	cout << solution.findLexSmallestString("0011", 4, 2) << endl;
	cout << solution.findLexSmallestString("43987654", 7, 3) << endl;
}
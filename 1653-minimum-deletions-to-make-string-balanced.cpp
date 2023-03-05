#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumDeletions(string s) {
		int n = s.size(), leftb = 0, righta = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				++righta;
			}
		}
		int ans = righta;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				--righta;
			}
			else {
				++leftb;
			}
			ans = min(ans, leftb + righta);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumDeletions("aababbab") << endl;
	cout << solution.minimumDeletions("bbaaaaabb") << endl;
	cout << solution.minimumDeletions("bbbabbb") << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int beautySum(string s) {
		int ans = 0, n = s.size();
		int max_, min_;
		for (int i = 0; i < n; i++) {
			vector<int> cnt(26);
			for (int j = i; j < n; j++) {
				++cnt[s[j] - 'a'];
				if (j > i + 1) {
					max_ = 0, min_ = 501;
					for (auto &c : cnt) {
						if (c) {
							max_ = max(max_, c);
							min_ = min(min_, c);
						}
					}
					ans += max_ - min_;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.beautySum("aabcb") << endl;
	cout << solution.beautySum("aabcbaa") << endl;
}
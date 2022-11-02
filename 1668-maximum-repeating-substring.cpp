#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int ans = 0, n = sequence.size(), l = word.size();
		for (int i = 0; i <= n - l; i++) {
			int curr = 0;
			for (int j = i; j <= n - l; j += l) {
				if (sequence.substr(j, l) == word) {
					++curr;
				}
				else {
					break;
				}
			}
			ans = max(ans, curr);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxRepeating("ababc", "ab") << endl;
	cout << solution.maxRepeating("ababc", "ba") << endl;
	cout << solution.maxRepeating("ababc", "ac") << endl;
	cout << solution.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba") << endl; // 5
	cout << solution.maxRepeating("a", "a") << endl; // 1
}

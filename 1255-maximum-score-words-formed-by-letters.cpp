#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		int n = words.size(), ans = 0;
		vector<int> count(26);
		for (auto c : letters) {
			++count[c - 'a'];
		}
		for (int s = 1; s < (1 << n); s++) {
			vector<int> wordCount(26);
			for (int k = 0; k < n; k++) {
				if (s & (1 << k)) {
					for (auto &c : words[k]) {
						++wordCount[c - 'a'];
					}
				}
			}
			bool ok = true;
			int sum = 0;
			for (int i = 0; i < 26; i++) {
				ok = ok && (wordCount[i] <= count[i]);
				if (ok) {
					sum += score[i] * wordCount[i];
				}
				else {
					break;
				}
			}
			if (ok) {
				ans = max(ans, sum);
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxScoreWords(vector<string> {"dog", "cat", "dad", "good"}, vector<char> {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'}, vector<int> {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << endl;
	cout << solution.maxScoreWords(vector<string> {"xxxz", "ax", "bx", "cx"}, vector<char> {'z', 'a', 'b', 'c', 'x', 'x', 'x'}, vector<int> {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10}) << endl;
	cout << solution.maxScoreWords(vector<string> {"leetcode"}, vector<char> {'l', 'e', 't', 'c', 'o', 'd'}, vector<int> {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}) << endl;
}
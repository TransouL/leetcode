#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int expressiveWords(string s, vector<string>& words) {
		vector<char> letters;
		vector<int> stats;
		char curr = 0, cnt = 0;
		for (auto &ch : s) {
			if (ch != curr){
				letters.push_back(curr);
				stats.push_back(cnt);
				curr = ch;
				cnt = 1;
			}
			else {
				++cnt;
			}
		}
		letters.push_back(curr);
		stats.push_back(cnt);

		int ans = 0;
		for (auto &word : words) {
			word += '0';
			bool is = true;
			int pos = 0;
			char curr = 0, cnt = 0;
			for (auto &ch : word) {
				if (ch != curr){
					if (pos >= letters.size() || curr != letters[pos] || cnt > stats[pos] || (stats[pos] < 3 && cnt != stats[pos])) {
						is = false;
						break;
					}
					curr = ch;
					cnt = 1;
					++pos;
				}
				else {
					++cnt;
				}
			}
			if (is && pos == letters.size()) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.expressiveWords("heeellooo", vector<string>{"hello", "hi", "helo"}) << endl;
	cout << solution.expressiveWords("abcd", vector<string>{"abc"}) << endl;
}
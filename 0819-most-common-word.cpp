#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		paragraph += '.';
		unordered_map<string, int> stats;
		int start = 0;
		bool valid = false;
		for (int i = 0; i < paragraph.length(); i++) {
			char ch = paragraph[i];
			if (!isalpha(ch)) {
				if (valid) {
					string word = paragraph.substr(start, i - start);
					if (find(banned.begin(), banned.end(), word) == banned.end()) {
						stats[word] += 1;
					}
					valid = false;
				}
			}
			else {
				paragraph[i] = tolower(paragraph[i]);
				if (!valid) {
					start = i;
					valid = true;
				}
			}
		}

		int maxCount = 0;
		string ans;
		for (auto it = stats.begin(); it != stats.end(); ++it) {
			string key = it->first;
			int value = it->second;
			if (maxCount < value) {
				maxCount = value;
				ans = key;
			}
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", vector<string> {"hit"}) << endl;
}

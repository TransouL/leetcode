#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		string ans = "";
		int ansLen = 0;
		unordered_set<string> combinedWords;
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			int wordLen = word.size();
			if (word.size() == 1) {
				if (ansLen == 0) {
					ans = word;
					ansLen = 1;
				}
				combinedWords.emplace(word);
			}
			else {
				if (combinedWords.count(word.substr(0, wordLen - 1))) {
					if (wordLen > ansLen) {
						ans = word;
						ansLen = wordLen;
					}
					combinedWords.emplace(word);
				}
			}
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.longestWord(vector<string> {"w", "wo", "wor", "worl", "world"}) << endl;
	cout << solution.longestWord(vector<string> {"a", "banana", "app", "appl", "ap", "apply", "apple"}) << endl;
	cout << solution.longestWord(vector<string> {"rac", "rs", "ra", "on", "r", "otif", "o", "onpdu", "rsf", "rs", "ot", "oti", "racy", "onpd"}) << endl; // "otif"
	cout << solution.longestWord(vector<string> {"gbra", "jy", "pl", "zn", "gb", "j", "jyh", "jyhm", "plr", "znicn", "p", "gbr", "zni", "znic", "aq"}) << endl; // "jyhm"
}

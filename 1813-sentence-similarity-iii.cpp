#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	vector<string> split(const string &str, char target) {
		vector<string> res;
		string s(str);
		int pos = 0;
		while (pos < s.size()) {
			while (pos < s.size() && s[pos] == target) {
				++pos;
			}
			int start = pos;
			while (pos < s.size() && s[pos] != target) {
				++pos;
			}
			if (pos > start) {
				res.emplace_back(s.substr(start, pos - start));
			}
		}
		return res;
	}

public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		vector<string> words1 = split(sentence1, ' ');
		vector<string> words2 = split(sentence2, ' ');
		int i = 0, j = 0;
		while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
			++i;
		}
		while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - j - 1] == words2[words2.size() - j - 1]) {
			++j;
		}
		return i + j == min(words1.size(), words2.size());
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.areSentencesSimilar("My name is Haley", "My Haley") << endl;
	cout << solution.areSentencesSimilar("of", "A lot of words") << endl;
	cout << solution.areSentencesSimilar("Eating right now", "Eating") << endl;
	cout << solution.areSentencesSimilar("Luky", "Lucccky") << endl;
}
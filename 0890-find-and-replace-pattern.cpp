#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	string trans(string word) {
		unordered_map<char, char> mapping;
		string res = "";
		int used = 0;
		for (int i = 0; i < word.size(); i++) {
			if (mapping.count(word[i])) {
				res += mapping[word[i]];
			}
			else {
				mapping[word[i]] = 'a' + used;
				res += 'a' + used;
				++used;
			}
		}
		return res;
	}

public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		string patternTrans = trans(pattern);
		vector<string> ans;
		for (auto &word : words) {
			if (trans(word) == patternTrans){
				ans.push_back(word);
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findAndReplacePattern(vector<string> {"abc", "deq", "mee", "aqq", "dkd", "ccc"}, "abb"));
	printVector(solution.findAndReplacePattern(vector<string> {"badc", "abab", "dddd", "dede", "yyxx"}, "baba"));
}

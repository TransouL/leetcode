#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		int orderMap[26];
		for (int i = 0; i < 26; i++) {
			orderMap[order[i] - 'a'] = i;
		}

		int n = words.size();
		for (int i = 0; i < n - 1; i++) {
			string word1 = words[i], word2 = words[i + 1];
			bool flag = false;
			for (int j = 0; j < word1.size() && j < word2.size(); ++j) {
				if (orderMap[word1[j] - 'a'] > orderMap[word2[j] - 'a']) {
					return false;
				}
				else if (orderMap[word1[j] - 'a'] < orderMap[word2[j] - 'a']) {
					flag = true;
					break;
				}
			}
			if (!flag && word1.size() > word2.size()){
				return false;
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isAlienSorted(vector<string> {"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz") << endl;
	cout << solution.isAlienSorted(vector<string> {"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz") << endl;
	cout << solution.isAlienSorted(vector<string> {"apple", "app"}, "abcdefghijklmnopqrstuvwxyz") << endl;
}

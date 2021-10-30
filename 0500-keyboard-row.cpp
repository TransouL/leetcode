#include <vector>
#include <iostream>
#include <string>

using namespace std;
const vector<string> keyboard = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> ans;
		for (string word : words) {
			int firstIdx = -1;
			for (size_t i = 0; i < 3; ++i){
				if (keyboard[i].find(tolower(word[0])) != string::npos){
					firstIdx = i;
					break;
				}
			}
			bool isValid = true;
			for (size_t i = 1; i < word.size(); ++i) {
				if (keyboard[firstIdx].find(tolower(word[i])) == string::npos){
					isValid = false;
					break;
				}
			}
			if (isValid){
				ans.emplace_back(word);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	for (auto var : solution.findWords(vector<string> { "Hello", "Alaska", "Dad", "Peace" })) cout << var << " "; cout << endl;
	for (auto var : solution.findWords(vector<string> { "omk"})) cout << var << " "; cout << endl;
	for (auto var : solution.findWords(vector<string> {"adsdf", "sfd" })) cout << var << " "; cout << endl;
}

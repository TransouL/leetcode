#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string toGoatLatin(string sentence) {
		sentence += ' ';
		string ans = "";
		int wordCnt = 1, start = 0;
		bool isVowel = false;
		for (int i = 0; i < sentence.length(); i++) {
			char ch = tolower(sentence[i]);
			if (ch == ' ') {
				if (isVowel) {
					ans += sentence.substr(start, i - start) + "ma";
				}
				else {
					ans += sentence.substr(start + 1, i - start - 1);
					ans += sentence[start];
					ans += "ma";
				}
				ans.append(wordCnt++, 'a');
				ans += " ";
				start = i + 1;
			}
			else {
				if (i == start) {
					isVowel = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
				}
			}
		}
		ans.pop_back();

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.toGoatLatin("I speak Goat Latin") << endl;
	cout << solution.toGoatLatin("The quick brown fox jumped over the lazy dog") << endl;
}

#include <iostream>

using namespace std;

class Solution {
public:
	int countValidWords(string sentence) {
		int ans = 0, start = 0, curr = 0, n = sentence.length(), hyphen = -1, punctuation = -1;
		bool valid = true;
		while (curr < n) {
			if (sentence[curr] == ' ') {
				if (start < curr) {
					if (valid && hyphen != curr - 1) {
						++ans;
					}
				}
				start = ++curr;
				hyphen = -1, punctuation = -1;
				valid = true;
				continue;
			}

			if (valid) {
				if (sentence[curr] >= '0' && sentence[curr] <= '9') {
					valid = false;
				}
				else if (sentence[curr] == '-') {
					if (punctuation == -1 && curr != start && hyphen == -1) {
						hyphen = curr;
					}
					else {
						valid = false;
					}
				}
				else if (sentence[curr] >= 'a' && sentence[curr] <= 'z') {
					if (punctuation != -1) {
						valid = false;
					}
				}
				else {
					if (punctuation == -1 && (hyphen == -1 || hyphen != curr - 1)) {
						punctuation = curr;
					}
					else {
						valid = false;
					}
				}
			}

			++curr;
		}

		if (valid && sentence[n - 1] != ' ' && sentence[n - 1] != '-') {
			++ans;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countValidWords("cat and  dog") << endl;
	cout << solution.countValidWords("!this  1-s b8d!") << endl;
	cout << solution.countValidWords("alice and  bob are playing stone-game10") << endl;
	cout << solution.countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.") << endl;
	cout << solution.countValidWords("-") << endl;
	cout << solution.countValidWords("a-") << endl;
	cout << solution.countValidWords("!") << endl;
	cout << solution.countValidWords("q-, ") << endl;
}

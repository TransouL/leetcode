#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string decodeMessage(string key, string message) {
		char cur = 'a';
		unordered_map<char, char> rules;

		for (char c : key) {
			if (c != ' ' && !rules.count(c)) {
				rules[c] = cur;
				++cur;
			}
		}

		for (char& c : message) {
			if (c != ' ') {
				c = rules[c];
			}
		}

		return message;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv") << endl;
}
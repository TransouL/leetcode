#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string letters[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> codes;
		for (auto &word : words) {
			string code;
			for (auto &ch : word) {
				code += letters[ch - 'a'];
			}
			codes.emplace(code);
		}
		return codes.size();
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.uniqueMorseRepresentations(vector<string> {"gin", "zen", "gig", "msg"}) << endl;
	cout << solution.uniqueMorseRepresentations(vector<string> {"a"}) << endl;
}

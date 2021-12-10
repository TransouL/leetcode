#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		int statsLicense[26] = { 0 };
		for (auto &ch : licensePlate)
			if (ch >= 'A')
				statsLicense[tolower(ch) - 'a']++;
		string *ans = nullptr;
		for (auto &word : words){
			int statsWord[26] = { 0 };
			for (auto &ch : word)
				if (ch >= 'A')
					statsWord[tolower(ch) - 'a']++;
			bool completed = true;
			for (size_t i = 0; i < 26; i++)
				if (statsLicense[i] > statsWord[i])
					completed = false;
			if (completed) {
				if (ans == nullptr)
					ans = &word;
				else if (ans->length() > word.length())
					ans = &word;
			}
		}
		return *ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.shortestCompletingWord("1s3 PSt", vector<string> {"step", "steps", "stripe", "stepple"}) << endl;
	cout << solution.shortestCompletingWord("1s3 456", vector<string> {"looks", "pest", "stew", "show"}) << endl;
	cout << solution.shortestCompletingWord("Ah71752", vector<string> {"suggest", "letter", "of", "husband", "easy", "education", "drug", "prevent", "writer", "old"}) << endl;
	cout << solution.shortestCompletingWord("OgEu755", vector<string> {"enough", "these", "play", "wide", "wonder", "box", "arrive", "money", "tax", "thus"}) << endl;
	cout << solution.shortestCompletingWord("iMSlpe4", vector<string> {"claim", "consumer", "student", "camera", "public", "never", "wonder", "simple", "thought", "use"}) << endl;
}
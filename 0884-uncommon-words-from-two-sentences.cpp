#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
	void split(const string& s, vector<string>& tokens, const string& delimiters = " "){
		string::size_type lastPos = s.find_first_not_of(delimiters, 0);
		string::size_type pos = s.find_first_of(delimiters, lastPos);
		while (string::npos != pos || string::npos != lastPos) {
			tokens.push_back(s.substr(lastPos, pos - lastPos));
			lastPos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, lastPos);
		}
	}

public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		vector<string> tokens, ans;
		split(s1 + ' ' + s2, tokens);
		unordered_map<string, int> freq;
		for (auto &token : tokens) {
			++freq[token];
		}
		for (auto &pair : freq) {
			string token = pair.first;
			int cnt = pair.second;
			if (cnt == 1) {
				ans.emplace_back(token);
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
	printVector(solution.uncommonFromSentences("this apple is sweet", "this apple is sour"));
	printVector(solution.uncommonFromSentences("apple apple", "banana"));
}

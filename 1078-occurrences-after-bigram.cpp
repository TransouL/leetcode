#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void split(const string& s, vector<string>& tokens, const string& delimiters = " "){
		string::size_type lastPos = s.find_first_not_of(delimiters, 0);
		string::size_type pos = s.find_first_of(delimiters, lastPos);
		while (string::npos != pos || string::npos != lastPos) {
			tokens.push_back(s.substr(lastPos, pos - lastPos));
			lastPos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, lastPos);
		}
	}

	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> words, ans;
		split(text, words);
		for (size_t i = 0; i < words.size() - 2; i++) {
			if (words[i] == first && words[i + 1] == second)
				ans.emplace_back(words[i + 2]);
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
	printVector(solution.findOcurrences("alice is a good girl she is a good student", "a", "good"));
	printVector(solution.findOcurrences("we will we will rock you", "we", "will"));
}

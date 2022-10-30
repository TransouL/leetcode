#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	void dfs(int step, string curr, vector<string> &ans) {
		if (step == curr.size()) {
			ans.push_back(curr);
		}
		else {
			dfs(step + 1, curr, ans);
			char c = curr[step];
			if (isalpha(c)) {
				dfs(step + 1, curr.substr(0, step) + (char)(c ^ 32) + curr.substr(step + 1), ans);
			}
		}
	}
public:
	vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		dfs(0, s, ans);
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.letterCasePermutation("a1b2"));
	printVector(solution.letterCasePermutation("3z4"));
}


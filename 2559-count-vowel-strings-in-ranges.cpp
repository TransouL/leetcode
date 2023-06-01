#include <iostream>
#include <vector>
using namespace std;

const vector<char> letters{ 'a', 'e', 'i', 'o', 'u' };
class Solution {
	bool check(string word) {
		bool head = false, tail = false;
		for (int i = 0; i < 5; i++) {
			if (letters[i] == word[0]) {
				head = true;
			}
			if (letters[i] == word.back()) {
				tail = true;
			}
		}
		return head && tail;
	}
public:
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		int n = words.size(), m = queries.size();
		vector<int> pre(n + 1);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = check(words[i]) ? pre[i] + 1 : pre[i];
		}
		vector<int> ans(m);
		for (int i = 0; i < m; i++) {
			ans[i] = pre[queries[i][1] + 1] - pre[queries[i][0]];
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.vowelStrings(vector<string>{"aba", "bcb", "ece", "aa", "e"}, vector<vector<int>> {{0, 2}, { 1, 4 }, { 1, 1 } }));
}
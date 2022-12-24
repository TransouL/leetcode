#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string largestMerge(string word1, string word2) {
		string ans = "";
		int i = 0, j = 0;
		while (i < word1.size() || j < word2.size()) {
			if (i < word1.size() && word1.substr(i) > word2.substr(j)) {
				ans += word1[i++];
			}
			else {
				ans += word2[j++];
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.largestMerge("cabaa", "bcaaa") << endl;
	cout << solution.largestMerge("abcabc", "abdcaba") << endl;
}
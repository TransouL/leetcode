#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		int n1 = word1.size(), n2 = word2.size();
		int n = max(n1, n2);
		string ans;
		for (int i = 0; i < n; i++) {
			if (i < n1)
				ans += word1[i];
			if (i < n2)
				ans += word2[i];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.mergeAlternately("abc", "pqr") << endl;
	cout << solution.mergeAlternately("ab", "pqrs") << endl;
	cout << solution.mergeAlternately("abcd", "pq") << endl;
}

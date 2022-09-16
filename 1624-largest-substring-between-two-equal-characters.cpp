#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		int first[26];
		fill_n(first, 26, -1);
		int ans = 0;
		for (int i = 0; i < s.size(); i++){
			if (first[s[i] - 'a'] != -1) {
				ans = max(ans, i - first[s[i] - 'a']);
			}
			else {
				first[s[i] - 'a'] = i;
			}
		}
		return ans - 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxLengthBetweenEqualCharacters("aa") << endl;
	cout << solution.maxLengthBetweenEqualCharacters("abca") << endl;
	cout << solution.maxLengthBetweenEqualCharacters("cbzxy") << endl;
	cout << solution.maxLengthBetweenEqualCharacters("cabbac") << endl;
}

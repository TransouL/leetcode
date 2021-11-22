#include <iostream>

using namespace std;

class Solution {
public:
	bool buddyStrings(string s, string goal) {
		size_t len = s.length();
		if (goal.length() != len)
			return false;
		
		if (s == goal){
			if (len > 26)
				return true;
			bool flag[26] = { false };
			for (size_t i = 0; i < len; i++){
				int pos = s[i] - 'a';
				if (flag[pos])
					return true;
				flag[pos] = true;
			}
			return false;
		}
		else {
			int diff1 = -1, diff2 = -1;
			for (size_t i = 0; i < len; i++){
				if (s[i] != goal[i]){
					if (diff1 == -1)
						diff1 = i;
					else if (diff2 == -1)
						diff2 = i;
					else
						return false;
				}
			}
			return diff2 != -1 && s[diff1] == goal[diff2] && s[diff2] == goal[diff1];
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.buddyStrings("ab", "ba") << endl;
	cout << solution.buddyStrings("ab", "ab") << endl;
	cout << solution.buddyStrings("aa", "aa") << endl;
	cout << solution.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
}
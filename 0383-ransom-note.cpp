#include <iostream>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int stats[26] = {0};
		for (auto &ch : magazine)
			stats[ch - 'a'] ++;
		for (auto &ch : ransomNote){
			if (stats[ch - 'a'] == 0)
				return false;
			stats[ch - 'a'] --;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canConstruct("a", "b") << endl;
	cout << solution.canConstruct("aa", "ab") << endl;
	cout << solution.canConstruct("aa", "aab") << endl;
}
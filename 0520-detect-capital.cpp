#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool canBeSupper = word[0] >= 'A' && word[0] <= 'Z' ? true : false, canBeLower = true;
		for (size_t i = 1; i < word.length(); i++){
			if (word[i] >= 'A' && word[i] <= 'Z'){
				if (canBeSupper)
					canBeLower = false;
				else
					return false;
			}
			else {
				if (canBeLower)
					canBeSupper = false;
				else
					return false;
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.detectCapitalUse("USA") << endl;
	cout << solution.detectCapitalUse("leetcode") << endl;
	cout << solution.detectCapitalUse("Google") << endl;
	cout << solution.detectCapitalUse("flaG") << endl;
}
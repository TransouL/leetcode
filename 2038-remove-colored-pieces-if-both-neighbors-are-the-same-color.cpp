#include <iostream>

using namespace std;

class Solution {
public:
	bool winnerOfGame(string colors) {
		bool currA = false;
		int currCount = 0, aAllowed = 0, bAllowed = 0;
		for (auto &c : colors) {
			if (c == 'A') {
				if (currA) {
					++currCount;
				}
				else {
					if (currCount > 2) {
						bAllowed += currCount - 2;
					}
					currA = true;
					currCount = 1;
				}
			}
			else {
				if (currA) {
					if (currCount > 2) {
						aAllowed += currCount - 2;
					}
					currA = false;
					currCount = 1;
				}
				else {
					++currCount;
				}
			}
		}
		if (currCount > 2) {
			if (currA) {
				aAllowed += currCount - 2;
			}
			else {
				bAllowed += currCount - 2;
			}
		}

		return aAllowed > bAllowed;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.winnerOfGame("AAABABB") << endl;
	cout << solution.winnerOfGame("AA") << endl;
	cout << solution.winnerOfGame("ABBBBBBBAAA") << endl;
}

#include <iostream>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int strongPasswordChecker(string password) {
		int n = password.length();
		bool hasLower = false, hasUpper = false, hasDigit = false;
		for (auto &ch : password) {
			if (islower(ch))
				hasLower = true;
			else if (isupper(ch))
				hasUpper = true;
			else if (isdigit(ch))
				hasDigit = true;
		}
		int categories = hasLower + hasUpper + hasDigit;

		if (n < 6)
			return max(6 - n, 3 - categories);

		if (n <= 20) {
			int replace = 0;
			int currCnt = 0;
			char currCh = '$';
			for (auto &ch : password) {
				if (ch == currCh)
					++currCnt;
				else {
					replace += currCnt / 3;
					currCnt = 1;
					currCh = ch;
				}
			}
			replace += currCnt / 3;
			return max(replace, 3 - categories);
		}
		else {
			int replace = 0, toRemove = n - 20;
			int rm2 = 0;
			int currCnt = 0;
			char currCh = '$';
			for (auto &ch : password) {
				if (ch == currCh)
					++currCnt;
				else {
					if (toRemove > 0 && currCnt >= 3) {
						if (currCnt % 3 == 0) {
							--toRemove;
							--replace;
						}
						else if (currCnt % 3 == 1) {
							++rm2;
						}
					}
					replace += currCnt / 3;
					currCnt = 1;
					currCh = ch;
				}
			}

			if (toRemove > 0 && currCnt >= 3) {
				if (currCnt % 3 == 0) {
					--toRemove;
					--replace;
				}
				else if (currCnt % 3 == 1) {
					++rm2;
				}
			}
			replace += currCnt / 3;

			int tmp = min(replace, rm2);
			int use2 = min(tmp, toRemove / 2);
			replace -= use2;
			toRemove -= use2 * 2;

			int use3 = min(replace, toRemove / 3);
			replace -= use3;

			return (n - 20) + max(replace, 3 - categories);
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.strongPasswordChecker("a") << endl;
	cout << solution.strongPasswordChecker("aA1") << endl;
	cout << solution.strongPasswordChecker("1337C0d3") << endl;
	cout << solution.strongPasswordChecker("ABABABABABABABABABAB1") << endl; // 2
	cout << solution.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc") << endl; // 8
}

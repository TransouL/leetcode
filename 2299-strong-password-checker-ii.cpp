#include <iostream>
using namespace std;

class Solution {
	const string spe = "!@#$%^&*()-+";
public:
	bool strongPasswordCheckerII(string password) {
		int n = password.size();
		if (n < 8) {
			return false;
		}
		bool hasLower = false, hasUpper = false, hasNum = false, hasSpe = false;
		for (int i = 0; i < n; i++) {
			char ch = password[i];
			if (i != 0) {
				if (ch == password[i - 1]) {
					return false;
				}
			}
			if (islower(ch)) {
				hasLower = true;
			}
			else if (isupper(ch)) {
				hasUpper = true;
			}
			else if (isdigit(ch)) {
				hasNum = true;
			}
			else if (spe.find(ch) != -1) {
				hasSpe = true;
			}
		}
		return hasLower && hasUpper && hasNum && hasSpe;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.strongPasswordCheckerII("IloveLe3tcode!") << endl;
	cout << solution.strongPasswordCheckerII("Me+You--IsMyDream") << endl;
	cout << solution.strongPasswordCheckerII("1aB!") << endl;
}
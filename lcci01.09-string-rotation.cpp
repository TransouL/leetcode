#include <iostream>
using namespace std;

class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		int n1 = s1.size(), n2 = s2.size();
		if (n1 == n2) {
			if (s1.empty() && s2.empty()) {
				return true;
			}
			for (int j = 0; j < n2; j++) {
				if (s2[j] == s1[0] && (s2.substr(j) + s2.substr(0, j) == s1)) {
					return true;
				}
			}
		}
		return false;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isFlipedString("waterbottle", "erbottlewat") << endl;
	cout << solution.isFlipedString("aa", "aba") << endl;
	cout << solution.isFlipedString("", "") << endl;
}

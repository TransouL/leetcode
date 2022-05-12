#include <iostream>
using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second) {
		int n1 = first.length(), n2 = second.length();
		if (n1 - n2 < -1 || n1 - n2 > 1)
			return false;
		bool edited = false;

		if (n1 == n2) {
			for (int i = 0; i < n1; i++) {
				if (first[i] != second[i]) {
					if (edited) {
						return false;
					}
					else {
						edited = true;
					}
				}
			}
			return true;
		}
		else {
			for (int i = 0, j = 0; i < n1; i++, j++) {
				if (first[i] != second[j]) {
					if (edited) {
						return false;
					}
					else {
						if (n1 > n2) {
							--j;
						}
						else {
							--i;
						}
						edited = true;
					}
				}
			}
			return true;
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.oneEditAway("pale", "ple") << endl;
	cout << solution.oneEditAway("pales", "ple") << endl;
	cout << solution.oneEditAway("teacher", "bleacher") << endl;
}

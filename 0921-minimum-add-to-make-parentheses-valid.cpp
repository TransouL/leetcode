#include <iostream>
using namespace std;

class Solution {
public:
	int minAddToMakeValid(string s) {
		int ans = 0, left = 0;
		for (auto &ch : s) {
			if (ch == '(') {
				++left;
			}
			else {
				if (left > 0) {
					--left;
				}
				else {
					++ans;
				}
			}
		}
		return ans + left;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minAddToMakeValid("())") << endl;
	cout << solution.minAddToMakeValid("(((") << endl;
	cout << solution.minAddToMakeValid("()))((") << endl;
}

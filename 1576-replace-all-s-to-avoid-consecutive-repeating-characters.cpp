#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string modifyString(string s) {
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				for (char ch = 'a'; ch <= 'c'; ch++) {
					if ((i == 0 || s[i - 1] != ch) && (i == n - 1 || s[i + 1] != ch)){
						s[i] = ch;
						break;
					}
				}
			}
		}
		return s;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.modifyString("?zs") << endl;
	cout << solution.modifyString("ubv?w") << endl;
	cout << solution.modifyString("j?qg??b") << endl;
	cout << solution.modifyString("??yw?ipkj?") << endl;
}

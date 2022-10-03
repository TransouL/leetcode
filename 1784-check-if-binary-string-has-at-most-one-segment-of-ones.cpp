#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool checkOnesSegment(string s) {
		int state = 0;
		for (auto &ch : s) {
			if (state == 0) {
				if (ch == '1') {
					state = 1;
				}
			}
			else if (state == 1) {
				if (ch == '0') {
					state = 2;
				}
			}
			else {
				if (ch == '1') {
					return false;
				}
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.checkOnesSegment("1001") << endl;
	cout << solution.checkOnesSegment("110") << endl;
}

#include <iostream>
using namespace std;

class Solution {
public:
	int countTime(string time) {
		int ans;
		if (time[0] == '?') {
			if (time[1] == '?') {
				ans = 24;
			}
			else {
				if (time[1] - '0' >= 4) {
					ans = 2;
				}
				else {
					ans = 3;
				}
			}
		}
		else {
			if (time[1] == '?') {
				if (time[0] == '2') {
					ans = 4;
				}
				else {
					ans = 10;
				}
			}
			else {
				ans = 1;
			}
		}
		
		if (time[3] == '?'){
			ans *= 6;
		}
		if (time[4] == '?'){
			ans *= 10;
		}

		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countTime("?5:00") << endl;
	cout << solution.countTime("0?:0?") << endl;
	cout << solution.countTime("??:??") << endl;
	cout << solution.countTime("?4:22") << endl;
}
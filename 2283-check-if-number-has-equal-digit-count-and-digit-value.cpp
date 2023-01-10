#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool digitCount(string num) {
		int n = num.size();
		int stats[10] = { 0 };
		for (auto &ch : num) {
			++stats[ch - '0'];
		}
		for (int i = 0; i < n; i++) {
			if (stats[i] != (num[i] - '0')) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.digitCount("1210") << endl;
	cout << solution.digitCount("030") << endl;
}
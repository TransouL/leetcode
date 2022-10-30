#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int magicalString(int n) {
		if (n < 4) {
			return 1;
		}
		string s(n, '0');
		s[0] = '1', s[1] = '2', s[2] = '2';
		int ans = 1;
		int i = 2;
		int j = 3;
		while (j < n) {
			int size = s[i] - '0';
			int num = 3 ^ (s[j - 1] - '0');
			while (size-- > 0 && j < n) {
				s[j] = '0' + num;
				if (num == 1) {
					++ans;
				}
				++j;
			}
			++i;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.magicalString(6) << endl;
	cout << solution.magicalString(1) << endl;
}


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string getSmallestString(int n, int k) {
		string ans(n, 'a');
		k -= n;
		int index = n - 1;
		while (true) {
			if (k > 25) {
				ans[index] = 'z';
				k -= 25;
				--index;
			}
			else {
				ans[index] = 'a' + k;
				return ans;
			}
		}
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.getSmallestString(3, 27) << endl;
	cout << solution.getSmallestString(5, 73) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int binaryGap(int n) {
		int ans = 0;
		while (!(n & 1)) {
			n >>= 1;
		}
		int curr = 1;
		n >>= 1;
		while (n) {
			if (n & 1) {
				ans = max(ans, curr);
				curr = 1;
			}
			else {
				++curr;
			}
			n >>= 1;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.binaryGap(22) << endl;
	cout << solution.binaryGap(8) << endl;
	cout << solution.binaryGap(5) << endl;
}

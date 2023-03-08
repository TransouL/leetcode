#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumRecolors(string blocks, int k) {
		int b = 0;
		for (int i = 0; i < k; i++) {
			if (blocks[i] == 'B') {
				++b;
			}
		}
		int ans = k - b;
		for (int i = k; i < blocks.size(); i++) {
			if (blocks[i] != blocks[i - k]) {
				if (blocks[i] == 'B') {
					++b;
					ans = min(ans, k - b);
					if (ans == 0) {
						break;
					}
				}
				else {
					--b;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumRecolors("WBBWWBBWBW", 7) << endl;
	cout << solution.minimumRecolors("WBWBBBW", 2) << endl;
}
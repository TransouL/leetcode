#include <iostream>

using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int stats[5] = {0}; // b a l o n
		for (auto &ch : text) {
			switch (ch) {
			case 'b':
				++stats[0];
				break;
			case 'a':
				++stats[1];
				break;
			case 'l':
				++stats[2];
				break;
			case 'o':
				++stats[3];
				break;
			case 'n':
				++stats[4];
				break;
			default:
				break;
			}
		}
		int ans = stats[0];
		stats[2] /= 2;
		stats[3] /= 2;
		for (size_t i = 1; i < 5; i++) {
			ans = min(ans, stats[i]);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxNumberOfBalloons("nlaebolko") << endl;
	cout << solution.maxNumberOfBalloons("loonbalxballpoon") << endl;
	cout << solution.maxNumberOfBalloons("leetcode") << endl;
}

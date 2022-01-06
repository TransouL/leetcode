#include <iostream>
#include <string>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int maxDepth(string s) {
		int ans = 0, curr = 0;
		for (auto &ch : s) {
			if (ch == '(') {
				++curr;
				ans = max(ans, curr);
			}
			else if (ch == ')') {
				--curr;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxDepth("(1+(2*3)+((8)/4))+1") << endl;
	cout << solution.maxDepth("(1)+((2))+(((3)))") << endl;
	cout << solution.maxDepth("1+(2*3)/(2-1)") << endl;
	cout << solution.maxDepth("1") << endl;
}

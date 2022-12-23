#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int finalValueAfterOperations(vector<string>& operations) {
		int ans = 0;
		for (auto &op : operations) {
			if (op[1] == '+') {
				++ans;
			}
			else {
				--ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.finalValueAfterOperations(vector<string> {"--X", "X++", "X++"}) << endl;
	cout << solution.finalValueAfterOperations(vector<string> {"++X", "++X", "X++"}) << endl;
	cout << solution.finalValueAfterOperations(vector<string> {"X++", "++X", "--X", "X--"}) << endl;
}
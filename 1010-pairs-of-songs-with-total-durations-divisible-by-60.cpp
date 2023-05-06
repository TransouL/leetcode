#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int rem[60]{};
		for (auto &t : time) {
			++rem[t % 60];
		}
		int ans = (long)rem[0] * (rem[0] - 1) / 2 + (long)rem[30] * (rem[30] - 1) / 2;
		for (int i = 1; i < 30; i++) {
			ans += rem[i] * rem[60 - i];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.numPairsDivisibleBy60(vector<int>{30, 20, 150, 100, 40}) << endl;
	cout << solution.numPairsDivisibleBy60(vector<int>{60, 60, 60}) << endl;
}
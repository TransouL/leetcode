#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int fillCups(vector<int>& amount) {
		int sum_ = amount[0] + amount[1] + amount[2], max_ = max(max(amount[0], amount[1]), amount[2]);
		if (sum_ > max_ * 2) {
			return (sum_ + 1) / 2;
		}
		else {
			return max_;
		}
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.fillCups(vector<int> {1, 4, 2}) << endl;
	cout << solution.fillCups(vector<int> {5, 4, 4}) << endl;
	cout << solution.fillCups(vector<int> {5, 0, 0}) << endl;
}
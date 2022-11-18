#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int ans = 0, curr = 0;
		for (auto &diff : gain) {
			curr += diff;
			ans = max(ans, curr);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.largestAltitude(vector<int> {-5, 1, 5, 0, -7}) << endl;
	cout << solution.largestAltitude(vector<int> {-4, -3, -2, -1, 4, 3, 2}) << endl;
}
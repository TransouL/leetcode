#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int arraySign(vector<int>& nums) {
		bool ans = true;
		for (auto &num : nums) {
			if (num == 0) {
				return 0;
			}
			else if (num < 0) {
				ans = !ans;
			}
		}
		return ans ? 1 : -1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.arraySign(vector<int>{-1, -2, -3, -4, 3, 2, 1}) << endl;
	cout << solution.arraySign(vector<int>{1, 5, 0, 2, -3}) << endl;
	cout << solution.arraySign(vector<int>{-1, 1, -1, 1, -1}) << endl;
}


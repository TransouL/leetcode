#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int gcd(int a, int b) {
		return b != 0 ? gcd(b, a % b) : a;
	}

public:
	int countDifferentSubsequenceGCDs(vector<int>& nums) {
		int maxVal = *max_element(nums.begin(), nums.end());
		vector<bool> occured(maxVal + 1, false);
		for (auto & num : nums) {
			occured[num] = true;
		}
		int ans = 0;
		for (int i = 1; i <= maxVal; i++) {
			int subGcd = 0;
			for (int j = i; j <= maxVal; j+=i) {
				if (occured[j]) {
					if (subGcd == 0) {
						subGcd = j;
					}
					else {
						subGcd = gcd(subGcd, j);
					}
					if (subGcd == i) {
						++ans;
						break;
					}
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countDifferentSubsequenceGCDs(vector<int>{6, 10, 3}) << endl;
	cout << solution.countDifferentSubsequenceGCDs(vector<int>{5, 15, 40, 5, 6}) << endl;
}
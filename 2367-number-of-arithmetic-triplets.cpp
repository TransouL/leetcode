#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int arithmeticTriplets(vector<int>& nums, int diff) {
		vector<int> expect1(200), expect2(200);
		int curr1 = 0, curr2 = 0, len1 = 0, len2 = 0, ans = 0;
		for (auto num : nums) {
			while (curr2 < len2 && num > expect2[curr2]) {
				++curr2;
			}
			bool flag2 = true;
			if (curr2 < len2 && num == expect2[curr2]) {
				++ans;
				++curr2;
				expect2[len2++] = num + diff;
				flag2 = false;
			}
			if (flag2) {
				while (curr1 < len1 && num > expect1[curr1]) {
					++curr1;
				}
				if (curr1 < len1 && num == expect1[curr1]) {
					++curr1;
					expect2[len2++] = num + diff;
				}
				else {
					expect1[len1++] = num + diff;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.arithmeticTriplets(vector<int> {0, 1, 4, 6, 7, 10}, 3) << endl;
	cout << solution.arithmeticTriplets(vector<int> {4, 5, 6, 7, 8, 9}, 2) << endl;
}
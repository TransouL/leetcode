#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	void update(int &mn1, int &mn2, int &num) {
		if (mn1 == 0) {
			mn1 = num;
		}
		else {
			if (mn2 == 0) {
				if (mn1 < num) {
					mn2 = num;
				}
				else {
					mn2 = mn1;
					mn1 = num;
				}
			}
			else {
				if (mn1 < num) {
					if (mn2 > num) {
						mn2 = num;
					}
				}
				else {
					mn2 = mn1;
					mn1 = num;
				}
			}
		}
	}

public:
	int maxSumDivThree(vector<int>& nums) {
		int ans = 0, mn11 = 0, mn12 = 0, mn21 = 0, mn22 =0;
		for (auto &num : nums) {
			ans += num;
			switch (num % 3) {
			case 1:
				update(mn11, mn12, num);
				break;
			case 2:
				update(mn21, mn22, num);
				break;
			default:
				break;
			}
		}

		int toReduce = 0;
		switch (ans % 3) {
		case 1:
			toReduce = mn11;
			if (toReduce == 0 || (mn21 != 0 && mn22 != 0 && toReduce > mn21 + mn22)) {
				toReduce = mn21 + mn22;
			}
			break;
		case 2:
			toReduce = mn21;
			if (toReduce == 0 || (mn11 != 0 && mn12 != 0 && toReduce > mn11 + mn12)) {
				toReduce = mn11 + mn12;
			}
			break;
		default:
			break;
		}
		return ans - toReduce;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxSumDivThree(vector<int>{3, 6, 5, 1, 8}) << endl;
	cout << solution.maxSumDivThree(vector<int>{4}) << endl;
	cout << solution.maxSumDivThree(vector<int>{1, 2, 3, 4, 4}) << endl;
}
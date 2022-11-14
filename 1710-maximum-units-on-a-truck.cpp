#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		auto cmp = [&](const vector<int> &x, const vector<int> &y) {
			return x[1] > y[1];
		};
		sort(boxTypes.begin(), boxTypes.end(), cmp);
		int ans = 0, curr = truckSize;
		for (auto boxType : boxTypes) {
			if (boxType[0] < curr) {
				ans += boxType[0] * boxType[1];
				curr -= boxType[0];
			}
			else {
				ans += curr * boxType[1];
				break;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maximumUnits(vector<vector<int>> {{1, 3}, { 2, 2 }, { 3, 1 }}, 4) << endl;
	cout << solution.maximumUnits(vector<vector<int>> {{5, 10}, { 2, 5 }, { 4, 7 }, {3, 9}}, 10) << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		int minCost[3] = { 0, 0, 0 };
		for (auto house : costs){
			int min0 = min(minCost[1], minCost[2]) + house[0];
			int min1 = min(minCost[0], minCost[2]) + house[1];
			int min2 = min(minCost[0], minCost[1]) + house[2];
			minCost[0] = min0;
			minCost[1] = min1;
			minCost[2] = min2;
		}
		return min(minCost[0], min(minCost[1], minCost[2]));
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minCost(vector<vector<int>>{ { 17, 2, 17 }, { 16, 16, 5 }, { 14, 3, 19 } }) << endl;
	cout << solution.minCost(vector<vector<int>>{ { 7, 6, 2 } }) << endl;
}
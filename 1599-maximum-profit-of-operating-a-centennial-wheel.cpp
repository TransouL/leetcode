#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
		int profit = 0, waitCustoms = 0, currRounds = 0, maxProfit = INT_MIN, ans;
		for (auto &c : customers) {
			waitCustoms += c;
			int roundCustoms = waitCustoms < 4 ? waitCustoms : 4;
			waitCustoms -= roundCustoms;
			profit += boardingCost * roundCustoms - runningCost;
			++currRounds;
			if (profit > maxProfit) {
				maxProfit = profit;
				ans = currRounds;
			}
		}
		int fullRounds = waitCustoms / 4;
		profit += boardingCost * fullRounds * 4 - runningCost * fullRounds;
		currRounds += fullRounds;
		if (profit > maxProfit) {
			maxProfit = profit;
			ans = currRounds;
		}
		profit += boardingCost * (waitCustoms % 4) - runningCost;
		if (profit > maxProfit) {
			maxProfit = profit;
			ans = currRounds + 1;
		}

		return maxProfit > 0 ? ans : -1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minOperationsMaxProfit(vector<int> {8, 3}, 5, 6) << endl;
	cout << solution.minOperationsMaxProfit(vector<int> {10, 9, 6}, 6, 4) << endl;
	cout << solution.minOperationsMaxProfit(vector<int> {3, 4, 0, 5, 1}, 1, 92) << endl;
	cout << solution.minOperationsMaxProfit(vector<int> {1, 0, 0, 0, 7}, 5, 6) << endl;
}
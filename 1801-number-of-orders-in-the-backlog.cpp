#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
	int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;
		for (auto &order : orders) {
			int price = order[0], amount = order[1], type = order[2];
			if (type == 0) {
				while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price) {
					auto sellOrder = sellOrders.top();
					sellOrders.pop();
					int sellAmount = min(amount, sellOrder.second);
					amount -= sellAmount;
					sellOrder.second -= sellAmount;
					if (sellOrder.second > 0) {
						sellOrders.push(sellOrder);
					}
				}
				if (amount > 0) {
					buyOrders.emplace(price, amount);
				}
			}
			else {
				while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
					auto buyOrder = buyOrders.top();
					buyOrders.pop();
					int buyAmount = min(amount, buyOrder.second);
					amount -= buyAmount;
					buyOrder.second -= buyAmount;
					if (buyOrder.second > 0) {
						buyOrders.push(buyOrder);
					}
				}
				if (amount > 0) {
					sellOrders.emplace(price, amount);
				}
			}
		}
		int ans = 0;
		while (!buyOrders.empty()) {
			ans = (ans + buyOrders.top().second) % MOD;
			buyOrders.pop();
		}
		while (!sellOrders.empty()) {
			ans = (ans + sellOrders.top().second) % MOD;
			sellOrders.pop();
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.getNumberOfBacklogOrders(vector<vector<int>> {{10, 5, 0}, { 15, 2, 1 }, { 25, 1, 1 }, { 30, 4, 0 }}) << endl;
	cout << solution.getNumberOfBacklogOrders(vector<vector<int>> {{7, 1000000000, 1}, { 15, 3, 0 }, { 5, 999999995, 0 }, { 5, 1, 1 }}) << endl;
	cout << solution.getNumberOfBacklogOrders(vector<vector<int>> {{19, 28, 0}, { 9, 4, 1 }, { 25, 15, 1 }}) << endl; // 39
}
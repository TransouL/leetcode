#include <iostream>

using namespace std;

class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int ans = numBottles, empty = numBottles;
		while (empty >= numExchange) {
			ans += empty / numExchange;
			empty = empty % numExchange + empty / numExchange;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numWaterBottles(9, 3) << endl;
	cout << solution.numWaterBottles(15, 4) << endl;
	cout << solution.numWaterBottles(5, 5) << endl;
	cout << solution.numWaterBottles(2, 3) << endl;
}
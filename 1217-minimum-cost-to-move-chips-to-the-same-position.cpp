#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		int odd = 0, even = 0;
		for (auto &i : position){
			if (i & 1){
				++odd;
			}
			else {
				++even;
			}
		}
		return min(odd, even);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minCostToMoveChips(vector<int>{ 1, 2, 3 }) << endl;
	cout << solution.minCostToMoveChips(vector<int>{ 2, 2, 2, 3, 3 }) << endl;
	cout << solution.minCostToMoveChips(vector<int>{ 1, 1000000000}) << endl;
}

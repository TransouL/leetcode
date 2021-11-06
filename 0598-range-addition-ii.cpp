#include <vector>
#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>> &ops) {
		int minA = m, minB = n;
		for (auto const &op : ops){
			minA = min(minA, op[0]);
			minB = min(minB, op[1]);
		}
		return minA * minB;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxCount(3, 3, vector<vector<int>>{{ 2, 2 }, { 3, 3 }}) << endl;
}

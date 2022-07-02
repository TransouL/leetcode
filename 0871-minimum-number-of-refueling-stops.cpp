#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		priority_queue<int> supplies;
		int ans = 0, currPos = 0, currFuel = startFuel;
		stations.push_back({target, 0});
		for (auto &station : stations) {
			int pos = station[0], supply = station[1];
			currFuel -= pos - currPos;
			currPos = pos;
			while (currFuel < 0) {
				if (supplies.empty()) {
					return -1;
				}
				currFuel += supplies.top();
				supplies.pop();
				++ans;
			}
			supplies.push(supply);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minRefuelStops(1, 1, vector<vector<int>> {}) << endl;
	cout << solution.minRefuelStops(100, 1, vector<vector<int>> {{10, 100}}) << endl;
	cout << solution.minRefuelStops(100, 10, vector<vector<int>> {{10, 60}, { 20, 30 }, { 30, 30 }, { 60, 40 }}) << endl;
}
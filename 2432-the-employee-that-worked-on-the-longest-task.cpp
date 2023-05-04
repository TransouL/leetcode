#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hardestWorker(int n, vector<vector<int>>& logs) {
		int curr = 0, mx = 0, ans = n;
		for (auto &log : logs) {
			int dur = log[1] - curr, id = log[0];
			if (dur > mx || (dur == mx && id < ans)) {
				mx = dur;
				ans = id;
			}
			curr = log[1];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.hardestWorker(10, vector<vector<int>>{{0, 3}, { 2, 5 }, { 0, 9 }, { 1, 15 }}) << endl;
	cout << solution.hardestWorker(26, vector<vector<int>>{{1, 1}, { 3, 7 }, { 2, 12 }, { 7, 17 }}) << endl;
	cout << solution.hardestWorker(2, vector<vector<int>>{{0, 10}, { 1, 20 }}) << endl;
}
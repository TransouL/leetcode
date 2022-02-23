#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> ans;
		ans.reserve(n);
		for (int i = 0; i < n; i++)
			ans.emplace_back(i);
		for (int row = 0; row < m; row++) {
			for (int i = 0; i < n; i++) {
				int curr = ans[i];
				if (curr == -1)
					continue;
				if (grid[row][curr] == 1)
					ans[i] = (curr == n - 1 || grid[row][curr + 1] == -1) ? -1 : curr + 1;
				else
					ans[i] = (curr == 0 || grid[row][curr - 1] == 1) ? -1 : curr - 1;
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findBall(vector<vector<int>> {{1, 1, 1, -1, -1}, { 1, 1, 1, -1, -1 }, { -1, -1, -1, 1, 1 }, { 1, 1, 1, 1, -1 }, { -1, -1, -1, -1, -1 }}));
	printVector(solution.findBall(vector<vector<int>> {{-1}}));
	printVector(solution.findBall(vector<vector<int>> {{1, 1, 1, 1, 1, 1}, { -1, -1, -1, -1, -1, -1 }, { 1, 1, 1, 1, 1, 1 }, { -1, -1, -1, -1, -1, -1 }}));
}

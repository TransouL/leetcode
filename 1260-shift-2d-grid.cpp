#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		size_t m = grid.size(), n = grid[0].size();
		if (k == m * n) {
			return grid;
		}
		vector<vector<int>> ans(m, vector<int>(n, 0));
		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < n; j++) {
				ans[(i + (j + k) / n) % m][(j + k % n) % n] = grid[i][j];
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<vector<T>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.shiftGrid(vector<vector<int>>{ {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }}, 1));
	printVector(solution.shiftGrid(vector<vector<int>>{ {3, 8, 1, 9}, { 19, 7, 2, 5 }, { 4, 6, 11, 10 }, { 12, 0, 21, 13 }}, 4));
	printVector(solution.shiftGrid(vector<vector<int>>{ {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }}, 9));
}

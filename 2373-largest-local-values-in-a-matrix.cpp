#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> ans(n - 2, vector<int>(n - 2));
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < n - 2; j++) {
				int tmp = grid[i][j];
				for (int ii = i; ii < i + 3; ii++) {
					for (int jj = j; jj < j + 3; jj++) {
						tmp = max(tmp, grid[ii][jj]);
					}
				}
				ans[i][j] = tmp;
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

int main(void) {
	Solution solution = Solution();
	printVector(solution.largestLocal(vector<vector<int>>{{9, 9, 8, 1}, { 5, 6, 2, 6 }, { 8, 2, 6, 4 }, { 6, 2, 2, 2 }}));
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		bool direction = false;
		int i = 0, j = 0;
		vector<int> ans;
		while (i != m - 1 || j != n - 1) {
			ans.push_back(mat[i][j]);
			if (direction) {
				if (i == m - 1 && j == 0) {
					direction = false;
					j = 1;
				}
				else if (j == 0) {
					direction = false;
					++i;
				}
				else if (i == m - 1) {
					direction = false;
					++j;
				}
				else {
					++i;
					--j;
				}
			}
			else {
				if (i == 0 && j == n - 1) {
					direction = true;
					i = 1;
				}
				else if (i == 0) {
					direction = true;
					++j;
				}
				else if (j == n - 1) {
					direction = true;
					++i;
				}
				else {
					--i;
					++j;
				}
			}
		}
		ans.push_back(mat[m - 1][n - 1]);
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
	printVector(solution.findDiagonalOrder(vector<vector<int>> {{1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }}));
	printVector(solution.findDiagonalOrder(vector<vector<int>> {{1, 2}, { 3, 4 }}));
}
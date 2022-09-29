#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> flagM(m, false);
		vector<bool> flagN(n, false);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					flagM[i] = true;
					flagN[j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] != 0 && (flagM[i] || flagN[j])) {
					matrix[i][j] = 0;
				}
			}
		}
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
	vector<vector<int>> matrix = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
	solution.setZeroes(matrix);
	printVector(matrix);
	vector<vector<int>> matrix2 = { { 0, 1, 2, 0 }, { 3, 4, 5, 2 }, { 1, 3, 1, 5 } };
	solution.setZeroes(matrix2);
	printVector(matrix2);
}

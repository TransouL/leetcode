#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int m = rowSum.size(), n = colSum.size();
		vector<vector<int>> ans(m, vector<int>(n, 0));
		for (int i = 0, j = 0; i < m && j < n;) {
			int rs = rowSum[i], cs = colSum[j];
			if (rs < cs) {
				colSum[j] -= rs;
				ans[i++][j] = rs;
			}
			else {
				rowSum[i] -= cs;
				ans[i][j++] = cs;
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
	printVector(solution.restoreMatrix(vector<int>{3, 8}, vector<int>{4, 7}));
	printVector(solution.restoreMatrix(vector<int>{5, 7, 10}, vector<int>{8, 6, 8}));
}
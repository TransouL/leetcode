#include <iostream>
#include <vector>

using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		size_t m = matrix.size(), n = matrix[0].size();
		vector<int> rowMin(m, 100000), colMax(n, 1);
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				rowMin[i] = min(rowMin[i], matrix[i][j]);
				colMax[j] = max(colMax[j], matrix[i][j]);
			}
		}
		vector<int> ans;
		for (auto &i : rowMin) {
			if (find(colMax.begin(), colMax.end(), i) != colMax.end())
				ans.emplace_back(i);
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
	printVector(solution.luckyNumbers(vector<vector<int>>{{3, 7, 8}, { 9, 11, 13 }, { 15, 16, 17 }}));
	printVector(solution.luckyNumbers(vector<vector<int>>{{1, 10, 4, 2}, { 9, 3, 8, 7 }, { 15, 16, 17, 12 }}));
	printVector(solution.luckyNumbers(vector<vector<int>>{{7, 8}, { 1, 2 }}));
}

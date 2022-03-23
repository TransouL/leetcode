#include <iostream>
#include <vector>

using namespace std;

int dx[8] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int m = img.size(), n = img[0].size();
		vector<vector<int>> ans(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int tmp = img[i][j], count = 1;
				for (int d = 0; d < 8; d++) {
					int nx = i + dx[d], ny = j + dy[d];
					if (0 <= nx && nx < m && 0 <= ny && ny < n) {
						tmp += img[nx][ny];
						++count;
					}
				}
				ans[i][j] = tmp / count;
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &subv : v) {
		for (auto &e : subv) cout << e << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.imageSmoother(vector<vector<int>>{{1, 1, 1}, { 1, 0, 1 }, { 1, 1, 1 }}));
	printVector(solution.imageSmoother(vector<vector<int>>{{100, 200, 100}, { 200, 50, 200 }, { 100, 200, 100 }}));
}

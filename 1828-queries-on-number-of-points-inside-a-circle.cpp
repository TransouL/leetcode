#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		int m = points.size(), n = queries.size();
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int x = queries[i][0], y = queries[i][1], r = queries[i][2], tmp = 0;
			for (auto &point : points) {
				if (pow(point[0] - x, 2) + pow(point[1] - y, 2) <= r * r) {
					++tmp;
				}
			}
			ans[i] = tmp;
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.countPoints(vector<vector<int>>{{1, 3}, { 3, 3 }, { 5, 3 }, { 2, 2 }}, vector<vector<int>>{{2, 3, 1}, { 4, 3, 1 }, {1, 1, 2}}));
}
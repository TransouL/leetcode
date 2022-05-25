#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> fallingSquares(vector<vector<int>>& positions) {
		int n = positions.size();
		map<int, int> heightMap;
		heightMap[0] = 0;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int edge = positions[i][1];
			int left = positions[i][0], right = positions[i][0] + edge - 1;
			auto lp = heightMap.upper_bound(left), rp = heightMap.upper_bound(right);
			int rHeight = prev(rp)->second;

			int height = 0;
			for (auto p = prev(lp); p != rp; p++) {
				height = max(height, p->second + edge);
			}

			heightMap.erase(lp, rp);

			heightMap[left] = height;
			if (rp == heightMap.end() || rp->first != right + 1) {
				heightMap[right + 1] = rHeight;
			}
			ans[i] = i == 0 ? height : max(ans[i - 1], height);
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
	printVector(solution.fallingSquares(vector<vector<int>> {{1, 2}, { 2, 3 }, { 6, 1 }}));
}

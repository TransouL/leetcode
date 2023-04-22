#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		int n = books.size();
		vector<int> f(n + 1);
		for (int i = 0; i < n; i++) {
			f[i + 1] = INT_MAX;
			int max_h = 0, left_w = shelfWidth;
			for (int j = i; j >= 0; --j) {
				left_w -= books[j][0];
				if (left_w < 0) {
					break;
				}
				max_h = max(max_h, books[j][1]);
				f[i + 1] = min(f[i + 1], f[j] + max_h);
			}
		}
		return f[n];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minHeightShelves(vector<vector<int>> {{1, 1}, { 2, 3 }, { 2, 3 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 2 }}, 4) << endl;
	cout << solution.minHeightShelves(vector<vector<int>> {{1, 3}, { 2, 4 }, { 3, 2 }}, 6) << endl;
}
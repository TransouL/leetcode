#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<double> row = { (double)poured };
		for (int i = 1; i <= query_row; i++) {
			vector<double> nextRow(i + 1, 0.0);
			for (int j = 0; j < row.size(); j++) {
				double volume = row[j];
				if (volume > 1) {
					nextRow[j] += (volume - 1) / 2;
					nextRow[j + 1] += (volume - 1) / 2;
				}
			}
			row = nextRow;
		}
		return min(1.0, row[query_glass]);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.champagneTower(1, 1, 1) << endl;
	cout << solution.champagneTower(2, 1, 1) << endl;
	cout << solution.champagneTower(100000009, 33, 17) << endl;
}
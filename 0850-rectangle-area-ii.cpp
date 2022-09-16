﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		int n = rectangles.size();
		vector<int> hbound;
		for (auto &rect : rectangles) {
			hbound.push_back(rect[1]);
			hbound.push_back(rect[3]);
		}
		sort(hbound.begin(), hbound.end());
		hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());
		int m = hbound.size();
		vector<int> seg(m - 1);

		vector<tuple<int, int, int>> sweep;
		for (int i = 0; i < n; i++) {
			sweep.emplace_back(rectangles[i][0], i, 1);
			sweep.emplace_back(rectangles[i][2], i, -1);
		}
		sort(sweep.begin(), sweep.end());

		long long ans = 0;
		for (int i = 0; i < sweep.size(); i++) {
			int j = i;
			while (j + 1 < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1])) {
				++j;
			}
			if (j + 1 == sweep.size()) {
				break;
			}

			for (int k = i; k <= j; k++) {
				auto&& t = sweep[k];
				int idx = get<1>(t), diff = get<2>(t);
				int left = rectangles[idx][1], right = rectangles[idx][3];
				for (int x = 0; x < m - 1; ++x) {
					if (left <= hbound[x] && hbound[x + 1] <= right) {
						seg[x] += diff;
					}
				}
			}
			int cover = 0;
			for (int k = 0; k < m - 1; ++k) {
				if (seg[k] > 0) {
					cover += (hbound[k + 1] - hbound[k]);
				}
			}
			ans += static_cast<long long>(cover)* (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
			i = j;
		}
		return ans % static_cast<int>(1e9 + 7);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.rectangleArea(vector<vector<int>> {{0, 0, 2, 2}, { 1, 0, 2, 3 }, { 1, 0, 3, 1 }}) << endl;
	cout << solution.rectangleArea(vector<vector<int>> {{0, 0, 1000000000, 1000000000} }) << endl;
}

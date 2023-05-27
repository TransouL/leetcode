#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	vector<int> merge(const vector<int> &f, const vector<int> &g, int k) {
		int left = f[0] + g[0], right = f.back() + g.back(), thres = 0, fs = f.size(), gs = g.size();
		k = min(k, fs * gs);
		while (left <= right) {
			int mid = (left + right) / 2;
			int rptr = g.size() - 1, cnt = 0;
			for (int lptr = 0; lptr < fs; lptr++) {
				while (rptr >= 0 && f[lptr] + g[rptr] > mid) {
					--rptr;
				}
				cnt += rptr + 1;
			}
			if (cnt >= k) {
				thres = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		vector<int> res;
		for (int i = 0; i < fs; i++) {
			for (int j = 0; j < gs; j++) {
				int sum = f[i] + g[j];
				if (sum < thres) {
					res.push_back(sum);
				}
				else {
					break;
				}
			}
		}
		while (res.size() < k) {
			res.push_back(thres);
		}
		sort(res.begin(), res.end());
		return res;
	}

public:
	int kthSmallest(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		vector<int> prev = mat[0];
		for (int i = 1; i < m; i++) {
			prev = move(merge(prev, mat[i], k));
		}
		return prev[k - 1];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.kthSmallest(vector<vector<int>> {{1, 3, 11}, { 2, 4, 6 }}, 5) << endl;
	cout << solution.kthSmallest(vector<vector<int>> {{1, 3, 11}, { 2, 4, 6 }}, 9) << endl;
	cout << solution.kthSmallest(vector<vector<int>> {{1, 10, 10}, { 1, 4, 5 }, { 2, 3, 6 }}, 7) << endl;
	cout << solution.kthSmallest(vector<vector<int>> {{1, 1, 10}, { 2, 2, 9 }}, 7) << endl;
}
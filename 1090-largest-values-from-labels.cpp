#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
		vector<pii> ps;
		int n = values.size();
		for (int i = 0; i < n; i++) {
			ps.emplace_back(make_pair(values[i], labels[i]));
		}
		sort(ps.rbegin(), ps.rend());
		unordered_map<int, int> stats;
		int ans = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			int v = ps[i].first, l = ps[i].second;
			if (stats[l] < useLimit) {
				ans += v;
				++cnt;
				if (cnt == numWanted) {
					break;
				}
				++stats[l];
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.largestValsFromLabels(vector<int> {5, 4, 3, 2, 1}, vector<int> {1, 1, 2, 2, 3}, 3, 1) << endl;
	cout << solution.largestValsFromLabels(vector<int> {5, 4, 3, 2, 1}, vector<int> {1, 3, 3, 3, 2}, 3, 2) << endl;
	cout << solution.largestValsFromLabels(vector<int> {9, 8, 8, 7, 6}, vector<int> {0, 0, 0, 1, 1}, 3, 1) << endl;
}
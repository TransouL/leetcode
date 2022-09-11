#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		int n = quality.size();
		vector<int> h(n, 0);
		iota(h.begin(), h.end(), 0);
		sort(h.begin(), h.end(), [&](int &a, int &b) {
			return quality[a] * wage[b] > quality[b] * wage[a];
		});
		double ans = 1e9;
		double totalq = 0.0;
		priority_queue<int, vector<int>, less<int>> q;
		for (int i = 0; i < k - 1; i++) {
			totalq += quality[h[i]];
			q.push(quality[h[i]]);
		}
		for (int i = k - 1; i < n; i++) {
			int idx = h[i];
			totalq += quality[idx];
			q.push(quality[idx]);
			double totalc = ((double)wage[idx] / quality[idx]) * totalq;
			ans = min(ans, totalc);
			totalq -= q.top();
			q.pop();
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.mincostToHireWorkers(vector<int> {10, 20, 5}, vector<int> {70, 50, 30}, 2) << endl;
	cout << solution.mincostToHireWorkers(vector<int> {3, 1, 10, 10, 1}, vector<int> {4, 8, 2, 2, 7}, 3) << endl;
}

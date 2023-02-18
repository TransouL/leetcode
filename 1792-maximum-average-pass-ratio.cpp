#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
	struct Ratio {
		int pass, total;
		bool operator < (const Ratio &oth) const {
			return (long long)(oth.total + 1) * oth.total * (total - pass) < (long long)(total + 1) * total * (oth.total - oth.pass);
		}
	};

public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<Ratio> q;
		for (auto &c : classes) {
			q.push({ c[0], c[1] });
		}

		for (int i = 0; i < extraStudents; i++) {
			auto r = q.top();
			q.pop();
			q.push({ r.pass + 1, r.total + 1 });
		}

		double ans = 0;
		while (!q.empty()) {
			auto r = q.top();
			q.pop();
			ans += 1.0 * r.pass / r.total;
		}

		return ans / classes.size();
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxAverageRatio(vector<vector<int>> {{1, 2}, { 3, 5 }, { 2, 2 }}, 2) << endl;
	cout << solution.maxAverageRatio(vector<vector<int>> {{2, 4}, { 3, 9 }, { 4, 5 }, { 2, 10 }}, 4) << endl;
}
#include <iostream>
#include <vector>
using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
	vector<int> delta;
	int ans, cnt, n;

	void dfs(vector<vector<int>>& requests, int pos) {
		if (pos == requests.size()) {
			for (auto &d : delta) {
				if (d != 0){
					return;
				}
			}
			ans = max(ans, cnt);
			return;
		}

		auto &r = requests[pos];
		int f = r[0], t = r[1];
		if (f == t) {
			++cnt;
			dfs(requests, pos + 1);
			--cnt;
			return;
		}

		dfs(requests, pos + 1);

		++cnt;
		--delta[f];
		++delta[t];
		dfs(requests, pos + 1);
		++delta[f];
		--delta[t];
		--cnt;
	}

public:
	int maximumRequests(int n, vector<vector<int>>& requests) {
		ans = cnt = 0;
		delta.resize(n);
		this->n = n;
		dfs(requests, 0);
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maximumRequests(5, vector<vector<int>> {{0, 1}, { 1, 0 }, { 0, 1 }, { 1, 2 }, { 2, 0 }, { 3, 4 }}) << endl;
	cout << solution.maximumRequests(3, vector<vector<int>> {{0, 0}, { 1, 2 }, { 2, 1 }}) << endl;
	cout << solution.maximumRequests(4, vector<vector<int>> {{0, 3}, { 3, 1 }, { 1, 2 }, { 2, 0 }}) << endl;
	cout << solution.maximumRequests(3, vector<vector<int>> {{1, 2}, { 1, 2 }, { 2, 2 }, { 0, 2 }, { 2, 1 }, { 1, 1 }, { 1, 2 }}) << endl;
}

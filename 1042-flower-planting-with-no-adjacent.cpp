#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<unordered_set<int>> adj(n);
		for (auto &path : paths) {
			adj[path[0] - 1].insert(path[1] - 1);
			adj[path[1] - 1].insert(path[0] - 1);
		}
		vector<int> ans(n);
		vector<int> flag(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= 4; j++) {
				if (!(flag[i] & 1 << j)) {
					ans[i] = j;
					for (auto &nei : adj[i]) {
						flag[nei] |= 1 << j;
					}
					break;
				}
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.gardenNoAdj(3, vector<vector<int>> {{1, 2}, { 2, 3 }, { 3, 1 }}));
	printVector(solution.gardenNoAdj(4, vector<vector<int>> {{1, 2}, { 3, 4 }}));
	printVector(solution.gardenNoAdj(4, vector<vector<int>> {{1, 2}, { 2, 3 }, { 3, 4 }, { 4, 1 }, { 1, 3 }, { 2, 4 }}));
}
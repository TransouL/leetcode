#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
		int n = nums.size();
		vector<int> indegrees(n + 1);
		vector<unordered_set<int>> graph(n + 1);
		for (auto &sequence : sequences) {
			for (int i = 1; i < sequence.size(); i++) {
				int prev = sequence[i - 1], next = sequence[i];
				if (!graph[prev].count(next)) {
					graph[prev].emplace(next);
					indegrees[next]++;
				}
			}
		}
		queue<int> qu;
		for (int i = 1; i <= n; i++) {
			if (indegrees[i] == 0) {
				qu.emplace(i);
			}
		}
		while (!qu.empty()) {
			if (qu.size() > 1) {
				return false;
			}
			int num = qu.front();
			qu.pop();
			for (auto &next : graph[num]) {
				indegrees[next]--;
				if (indegrees[next] == 0) {
					qu.emplace(next);
				}
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.sequenceReconstruction(vector<int>{ 1, 2, 3 }, vector<vector<int>> {{1, 2}, { 1, 3 }}) << endl;
	cout << solution.sequenceReconstruction(vector<int>{ 1, 2, 3 }, vector<vector<int>> {{1, 2}}) << endl;
	cout << solution.sequenceReconstruction(vector<int>{ 1, 2, 3 }, vector<vector<int>> {{1, 2}, { 1, 3 }, { 2, 3 }}) << endl;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	int minJumps(vector<int>& arr) {
		unordered_map<int, vector<int>> valtoIdx;
		for (int i = 0; i < arr.size(); i++) {
			valtoIdx[arr[i]].push_back(i);
		}
		unordered_set<int> visited;
		queue<pair<int, int>> q;
		q.emplace(0, 0);
		visited.emplace(0);
		while (!q.empty()) {
			auto p = q.front();
			int idx = p.first, step = p.second;
			q.pop();
			if (idx == arr.size() - 1) {
				return step;
			}
			int val = arr[idx];
			step++;
			if (valtoIdx.count(val)) {
				for (auto &i : valtoIdx[val]) {
					if (!visited.count(i)) {
						visited.emplace(i);
						q.emplace(i, step);
					}
				}
				valtoIdx.erase(val);
			}
			if (idx + 1 < arr.size() && !visited.count(idx + 1)) {
				visited.emplace(idx + 1);
				q.emplace(idx + 1, step);
			}
			if (idx - 1 >= 0 && !visited.count(idx - 1)) {
				visited.emplace(idx - 1);
				q.emplace(idx - 1, step);
			}
		}
		return -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minJumps(vector<int> {100, -23, -23, 404, 100, 23, 23, 23, 3, 404}) << endl;
	cout << solution.minJumps(vector<int> {7}) << endl;
	cout << solution.minJumps(vector<int> {7, 6, 9, 6, 9, 6, 9, 7}) << endl;
	cout << solution.minJumps(vector<int> {6, 1, 9}) << endl;
	cout << solution.minJumps(vector<int> {11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13}) << endl;
}

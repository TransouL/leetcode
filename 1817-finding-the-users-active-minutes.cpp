#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
		unordered_map<int, unordered_set<int>> active;
		for (auto &log : logs){
			active[log[0]].emplace(log[1]);
		}
		vector<int> ans(k, 0);
		for (auto &user : active) {
			++ans[user.second.size() - 1];
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.findingUsersActiveMinutes(vector<vector<int>>{{0, 5}, { 1, 2 }, { 0, 2 }, { 0, 5 }, { 1, 3 }}, 5));
	printVector(solution.findingUsersActiveMinutes(vector<vector<int>>{{1, 1}, { 2, 2 }, { 2, 3 }}, 4));
	printVector(solution.findingUsersActiveMinutes(vector<vector<int>>{{305589003, 4136}, { 305589004, 4139 }, { 305589004, 4141 }, { 305589004, 4137 }, { 305589001, 4139 }, { 305589001, 4139 }}, 6));
}
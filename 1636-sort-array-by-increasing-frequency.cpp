#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> stats;
		for (auto &num : nums) {
			++stats[num];
		}
		map<int, set<int, greater<int>>> reve;
		for (auto &pair : stats) {
			reve[pair.second].insert(pair.first);
		}
		vector<int> ans;
		for (auto &group : reve) {
			int count = group.first;
			for (auto &num : group.second) {
				for (int _ = 0; _ < count; _++) {
					ans.emplace_back(num);
				}
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.frequencySort(vector<int> {1, 1, 2, 2, 2, 3}));
	printVector(solution.frequencySort(vector<int> {2, 3, 1, 3, 2}));
	printVector(solution.frequencySort(vector<int> {-1, 1, -6, 4, 5, -6, 1, 4, 1}));
}

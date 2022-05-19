#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = intervals.size();
		map<int, int> mp;
		vector<int> ans(n, -1);
		if (n > 1) {
			for (int i = 0; i < n; i++) {
				mp[intervals[i][0]] = i;
			}
			for (int i = 0; i < n; i++) {
				auto it = mp.upper_bound(intervals[i][1] - 1);
				if (it != mp.end()) {
					ans[i] = it->second;
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
	printVector(solution.findRightInterval(vector<vector<int>> {{1, 2}}));
	printVector(solution.findRightInterval(vector<vector<int>> {{3, 4}, { 2, 3 }, { 1, 2 }}));
	printVector(solution.findRightInterval(vector<vector<int>> {{1, 4}, { 2, 3 }, { 3, 4 }}));
	printVector(solution.findRightInterval(vector<vector<int>> {{4, 5}, { 2, 3 }, { 1, 2 }}));  // [-1,0,1]
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<vector<int>> richerMap(n);
		for (auto &r : richer)
			richerMap[r[1]].emplace_back(r[0]);

		vector<int> leastQuiet(n, -1);
		for (int id = 0; id < n; id++)
			if (leastQuiet[id] == -1)
				find(leastQuiet, richerMap, quiet, id);
		return leastQuiet;
	}
private:
	void find(vector<int> &leastQuiet, vector<vector<int>> &richerMap, vector<int> &quiet, int &id) {
		int ret = id;
		for (auto &recherID : richerMap[id]) {
			if (leastQuiet[recherID] == -1)
				find(leastQuiet, richerMap, quiet, recherID);
			if (quiet[leastQuiet[recherID]] < quiet[ret])
				ret = leastQuiet[recherID];
		}
		leastQuiet[id] = ret;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.loudAndRich(vector<vector<int>>{{1, 0}, { 2, 1 }, { 3, 1 }, { 3, 7 }, { 4, 3 }, { 5, 3 }, { 6, 3 }}, vector<int> { 3, 2, 5, 4, 6, 1, 7, 0 }));
	printVector(solution.loudAndRich(vector<vector<int>>{}, vector<int>  { 0 }));
}
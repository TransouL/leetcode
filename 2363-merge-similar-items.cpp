#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
		map<int, int> stat;
		for (auto &item : items1) {
			stat[item[0]] += item[1];
		}
		for (auto &item : items2) {
			stat[item[0]] += item[1];
		}
		vector<vector<int>> ans;
		for (auto &p : stat) {
			ans.push_back({p.first, p.second});
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<vector<T>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.mergeSimilarItems(vector<vector<int>>{{1, 1}, { 4, 5 }, { 3, 8 }}, vector<vector<int>>{{3, 1}, { 1, 5 }}));
}
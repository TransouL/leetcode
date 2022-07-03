#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		vector<vector<int>> ans;
		int minDiff = INT_MAX;
		for (int i = 0; i < arr.size() - 1; i++) {
			int a = arr[i], b = arr[i + 1];
			int diff = b - a;
			if (diff == minDiff) {
				ans.push_back({ a, b });
			}
			else if (diff < minDiff) {
				minDiff = diff;
				ans.clear();
				ans.push_back({ a, b });
			}
		}
		return ans;
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.minimumAbsDifference(vector<int>{ 4, 2, 1, 3 }));
	printVector(solution.minimumAbsDifference(vector<int>{ 1, 3, 6, 10, 15 }));
	printVector(solution.minimumAbsDifference(vector<int>{ 3, 8, -10, 23, 19, -4, -14, 27 }));
}
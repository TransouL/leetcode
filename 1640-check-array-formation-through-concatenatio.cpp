#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		int n = arr.size(), m = pieces.size();
		for (int i = 0; i < n; i++) {
			bool found = false;
			for (int j = 0; j < m && !found; j++) {
				if (pieces[j][0] == arr[i]) {
					for (int k = 1; k < pieces[j].size(); k++) {
						++i;
						if (arr[i] != pieces[j][k]) {
							return false;
						}
					}
					found = true;
				}
			}
			if (!found) {
				return false;
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canFormArray(vector<int> {15, 88}, vector<vector<int>> {{88}, { 15 }}) << endl;
	cout << solution.canFormArray(vector<int> {49, 18, 16}, vector<vector<int>> {{16, 18, 49}}) << endl;
	cout << solution.canFormArray(vector<int> {91, 4, 64, 78}, vector<vector<int>> {{78}, { 4, 64 }, { 91 }}) << endl;
}
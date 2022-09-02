#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end());
		int ans = 1, last1 = pairs[0][0]-1,  curr1 = pairs[0][1];
		for (int i = 1; i < pairs.size(); i++) {
			if (curr1 < pairs[i][0]) {
				last1 = curr1;
				curr1 = pairs[i][1];
				++ans;
			}
			else if (curr1 == pairs[i][0]) {
			}
			else {
				if (last1 < pairs[i][0] && curr1 > pairs[i][1]) {
					curr1 = pairs[i][1];
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findLongestChain(vector<vector<int>> {{1, 2}, { 2, 3 }, { 3, 4 }}) << endl;
	cout << solution.findLongestChain(vector<vector<int>> {{1, 9}, { 2, 3 }, { 4, 5 }}) << endl;
	cout << solution.findLongestChain(vector<vector<int>> {{1, 2}, { 3, 9 }, { 4, 5 }, { 6, 7 }}) << endl;
}

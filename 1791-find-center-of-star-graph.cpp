#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findCenter(vector<vector<int>> {{1, 2}, { 2, 3 }, { 4, 2 }}) << endl;
	cout << solution.findCenter(vector<vector<int>> {{1, 2}, { 5, 1 }, { 1, 3 }, { 1, 4 }}) << endl;
}

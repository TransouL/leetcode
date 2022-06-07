#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) != (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isBoomerang(vector<vector<int>> {{1, 1}, { 2, 3 }, { 3, 2 }}) << endl;
	cout << solution.isBoomerang(vector<vector<int>> {{1, 1}, { 2, 2 }, { 3, 3 }}) << endl;
}

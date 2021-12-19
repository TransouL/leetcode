#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool trustmap[1001][1001];

class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		memset(trustmap, false, sizeof(trustmap));
		for (auto &t : trust) {
			trustmap[t[0]][0] = true;
			trustmap[t[1]][t[0]] = true;
		}
		for (int i = 1; i <= n; i++){
			if (!trustmap[i][0]) {
				bool isJudge = true;
				for (int j = 1; j <= n; j++){
					if (i != j && !trustmap[i][j]) {
						isJudge = false;
					}
				}
				if (isJudge){
					return i;
				}
			}
		}
		return -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findJudge(2, vector<vector<int>> {{1, 2}}) << endl;
	cout << solution.findJudge(3, vector<vector<int>> {{1, 3}, { 2, 3 }}) << endl;
	cout << solution.findJudge(3, vector<vector<int>> {{1, 3}, { 2, 3 }, { 3, 1 }}) << endl;
	cout << solution.findJudge(3, vector<vector<int>> {{1, 2}, { 2, 3 }}) << endl;
	cout << solution.findJudge(4, vector<vector<int>> {{1, 3}, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 4, 3 }}) << endl;
}
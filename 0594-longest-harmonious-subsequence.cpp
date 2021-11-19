#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int findLHS(vector<int>& nums) {
		map<int, int> cnts;
		for (auto &num : nums){
			cnts[num] += 1;
		}
		
		int ans = 0, lastNum = INT_MIN, lastCount = 0;
		for (auto &entry : cnts){
			int currNum = entry.first, currCount = entry.second;
			if (currNum == lastNum + 1){
				ans = max(ans, lastCount + currCount);
			}
			lastNum = currNum;
			lastCount = currCount;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findLHS(vector<int> { 1, 3, 2, 2, 5, 2, 3, 7 }) << endl;
	cout << solution.findLHS(vector<int> { 1, 2, 3, 4 }) << endl;
	cout << solution.findLHS(vector<int> { 1, 1, 1, 1 }) << endl;
}
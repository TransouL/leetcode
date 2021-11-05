#include <vector>
#include <iostream>
#include <unordered_map>

#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		unordered_map<int, int> map;
		int ans = 1;
		for (int num : arr){
			map[num] = map[num - difference] + 1;
			ans = max(ans, map[num]);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.longestSubsequence(vector<int> { 1, 2, 3, 4 }, 1) << endl;
	cout << solution.longestSubsequence(vector<int> { 1, 3, 5, 7 }, 1) << endl;
	cout << solution.longestSubsequence(vector<int> { 1, 5, 7, 8, 5, 3, 4, 2, 1 }, -2) << endl;
}
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		unsigned int n = nums.size();
		int ans = 0;
		for (size_t i = 0; i <= n; i++){
			ans ^= i;
		}
		for (int num : nums) {
			ans ^= num;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.missingNumber(vector<int> { 3, 0, 1 }) << endl;
	cout << solution.missingNumber(vector<int> { 0, 1 }) << endl;
	cout << solution.missingNumber(vector<int> { 9, 6, 4, 2, 3, 5, 7, 0, 1 }) << endl;
	cout << solution.missingNumber(vector<int> { 0 }) << endl;
}

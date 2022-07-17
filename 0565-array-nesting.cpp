#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int ans = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			while (nums[i] < n) {
				int num = nums[i];
				nums[i] = n;
				i = num;
				++cnt;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.arrayNesting(vector<int>{ 5, 4, 0, 3, 1, 6, 2 }) << endl;
}

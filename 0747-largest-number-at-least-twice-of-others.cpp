#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int max1 = nums[0], max2 = 0, ans = 0;
		for (int i = 1; i < nums.size(); i++){
			int num = nums[i];
			if (num > max1) {
				max2 = max1;
				max1 = num;
				ans = i;
			}
			else if (num != max1 && num > max2) {
				max2 = num;
			}
		}
		return max1 >= max2 * 2 ? ans : -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.dominantIndex(vector<int> {3, 6, 1, 0}) << endl;
	cout << solution.dominantIndex(vector<int> {1, 2, 3, 4}) << endl;
	cout << solution.dominantIndex(vector<int> {1}) << endl;
}

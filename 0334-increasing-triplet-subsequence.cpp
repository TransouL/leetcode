#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int min1 = nums[0], min2;
		bool getMin2 = false;
		for (auto &num : nums) {
			if (getMin2 && num > min2) {
				return true;
			}
			if (min1 > num){
				min1 = num;
			}
			if (num > min1){
				if (!getMin2) {
					min2 = num;
					getMin2 = true;
				}
				else if (min2 > num) {
					min2 = num;
				}				
			}
		}
		return false;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.increasingTriplet(vector<int> {1, 2, 3, 4, 5}) << endl;
	cout << solution.increasingTriplet(vector<int> {5, 4, 3, 2, 1}) << endl;
	cout << solution.increasingTriplet(vector<int> {2, 1, 5, 0, 4, 6}) << endl;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xorall = 0;
		for (auto num : nums) xorall ^= num;
		int lastbit = xorall == INT_MIN ? 1 : xorall & (-xorall);
		int ans1 = 0, ans2 = 0;
		for (auto num : nums) {
			if (num & lastbit)
				ans1 ^= num;
			else
				ans2 ^= num;
		}
		return{ ans1, ans2 };
	}
};

int main(void){
	Solution solution = Solution();
	for (auto num : solution.singleNumber(vector<int> { 1, 2, 1, 3, 2, 5 })) cout << num << " "; cout << endl;
	for (auto num : solution.singleNumber(vector<int> { -1, 0 })) cout << num << " "; cout << endl;
	for (auto num : solution.singleNumber(vector<int> { 0, 1 })) cout << num << " "; cout << endl;
	for (auto num : solution.singleNumber(vector<int> { INT_MIN, 0 })) cout << num << " "; cout << endl;
}

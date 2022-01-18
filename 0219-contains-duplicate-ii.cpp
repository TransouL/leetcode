#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_map<int, int> map;
		for (int i = 0; i < n; i++) {
			int curr = nums[i];
			if (map.count(curr) && i - map[curr] <= k) {
				return true;
			}
			map[curr] = i;
		}
		return false;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.containsNearbyDuplicate(vector<int> {1, 2, 3, 1}, 3) << endl;
	cout << solution.containsNearbyDuplicate(vector<int> {1, 0, 1, 1}, 1) << endl;
	cout << solution.containsNearbyDuplicate(vector<int> {1, 2, 3, 1, 2, 3}, 2) << endl;
	cout << solution.containsNearbyDuplicate(vector<int> {99, 99}, 2) << endl;
}

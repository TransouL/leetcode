#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		unordered_set<int> st;
		for (auto &num : nums) {
			if (num) {
				st.emplace(num);
			}
		}
		return st.size();
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minimumOperations(vector<int> {1, 5, 0, 3, 5}) << endl;
}
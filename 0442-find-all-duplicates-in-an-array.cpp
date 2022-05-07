#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			int x = abs(nums[i]);
			if (nums[x - 1] > 0) {
				nums[x - 1] = -nums[x - 1];
			}
			else {
				ans.push_back(x);
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findDuplicates(vector<int> {4, 3, 2, 7, 8, 2, 3, 1}));
	printVector(solution.findDuplicates(vector<int> {1, 1, 2}));
	printVector(solution.findDuplicates(vector<int> {1}));
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> applyOperations(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				nums[i] *= 2;
				nums[i + 1] = 0;
			}
		}
		int valueIdx = 0, assignIdx = 0, zeroCnt = 0;
		for (;;) {
			if (valueIdx == n)
				break;
			if (nums[valueIdx] == 0) {
				++zeroCnt;
			}
			else {
				nums[assignIdx] = nums[valueIdx];
				++assignIdx;
			}
			++valueIdx;
		}
		for (int i = assignIdx; i < n; i++) {
			nums[i] = 0;
		}
		return nums;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.applyOperations(vector<int>{1, 2, 2, 1, 1, 0}));
	printVector(solution.applyOperations(vector<int>{0, 1}));
	printVector(solution.applyOperations(vector<int>{847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272}));
}
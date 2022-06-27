#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		vector<int> arr = nums;
		sort(arr.begin(), arr.end());
		int mid = (1 + n) / 2;
		for (int i = 0, j = mid - 1, k = n - 1; i < n; i += 2, --j, --k) {
			nums[i] = arr[j];
			if (i + 1 < n) {
				nums[i + 1] = arr[k];
			}
		}
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	vector<int> nums = { 1, 5, 1, 1, 6, 4 };
	solution.wiggleSort(nums);
	printVector(nums);
	nums = { 1, 3, 2, 2, 3, 1 };
	solution.wiggleSort(nums);
	printVector(nums);
}
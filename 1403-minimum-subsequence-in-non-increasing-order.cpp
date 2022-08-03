#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		int n = nums.size();
		sort(nums.rbegin(), nums.rend());
		vector<int> presum(n + 1, 0);
		for (int i = 0; i < n; i++) {
			presum[i + 1] = presum[i] + nums[i];
		}

		int sum = presum[n], idx;
		if (sum & 1) {
			idx = lower_bound(presum.begin(), presum.end(), (sum + 1) / 2) - presum.begin();
		}
		else {
			idx = upper_bound(presum.begin(), presum.end(), sum / 2) - presum.begin();
		}
		return vector<int>(nums.begin(), nums.begin() + idx);
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.minSubsequence(vector<int>{ 4, 3, 10, 9, 8 }));
	printVector(solution.minSubsequence(vector<int>{ 4, 4, 7, 6, 7 }));
	printVector(solution.minSubsequence(vector<int>{ 6 }));
}

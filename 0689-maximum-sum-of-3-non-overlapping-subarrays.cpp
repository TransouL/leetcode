#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> ans;
		int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
		int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
		int sum3 = 0, maxSum123 = 0;
		for (int i = 0; i < k - 1; i++){
			sum1 += nums[i];
			sum2 += nums[i + k];
			sum3 += nums[i + 2 * k];
		}
		for (int i = k - 1; i < nums.size() - 2 * k; ++i) {
			sum1 += nums[i];
			sum2 += nums[i + k];
			sum3 += nums[i + 2 * k];

			if (sum1 > maxSum1) {
				maxSum1 = sum1;
				maxSum1Idx = i - k + 1;
			}
			if (maxSum1 + sum2 > maxSum12){
				maxSum12 = maxSum1 + sum2;
				maxSum12Idx1 = maxSum1Idx;
				maxSum12Idx2 = i + 1;
			}
			if (maxSum12 + sum3 > maxSum123){
				maxSum123 = maxSum12 + sum3;
				ans = { maxSum12Idx1, maxSum12Idx2, i + k + 1 };
			}

			sum1 -= nums[i - k + 1];
			sum2 -= nums[i + 1];
			sum3 -= nums[i + k + 1];
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
	printVector(solution.maxSumOfThreeSubarrays(vector<int>{1, 2, 1, 2, 6, 7, 5, 1 }, 2));
	printVector(solution.maxSumOfThreeSubarrays(vector<int>{1, 2, 1, 2, 1, 2, 1, 2, 1 }, 2));
}
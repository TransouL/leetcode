#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
class Solution {
public:
	int sumSubarrayMins(vector<int>& arr) {
		int n = arr.size();
		vector<int> monoStack;
		vector<int> left(n), right(n);
		for (int i = 0; i < n; i++) {
			while (!monoStack.empty() && arr[i] <= arr[monoStack.back()]) {
				monoStack.pop_back();
			}
			left[i] = i - (monoStack.empty() ? -1 : monoStack.back());
			monoStack.emplace_back(i);
		}
		monoStack.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!monoStack.empty() && arr[i] < arr[monoStack.back()]) {
				monoStack.pop_back();
			}
			right[i] = (monoStack.empty() ? n : monoStack.back()) - i;
			monoStack.emplace_back(i);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans + (long long)left[i] * right[i] * arr[i]) % MOD;
		}
		
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.sumSubarrayMins(vector<int>{3, 1, 2, 4}) << endl;
	cout << solution.sumSubarrayMins(vector<int>{11, 81, 94, 43, 3}) << endl;
	cout << solution.sumSubarrayMins(vector<int>{71, 55, 82, 55}) << endl; // 593
}


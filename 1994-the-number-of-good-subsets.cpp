#include <iostream>
#include <vector>

using namespace std;

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
int num_max = 30;
int mod = 1000000007;

class Solution {
public:
	int numberOfGoodSubsets(vector<int>& nums) {
		vector<int> freq(num_max + 1);
		for (auto &num : nums){
			++freq[num];
		}

		vector<int> dp(1 << 10);
		dp[0] = 1;
		for (int i = 0; i < freq[1]; ++i) {
			dp[0] = dp[0] * 2 % mod;
		}

		for (int i = 2; i <= num_max; ++i) {
			if (freq[i] == 0) {
				continue;
			}

			int subset = 0, x = i;
			bool check = true;
			for (int j = 0; j < 10; ++j) {
				int prime = primes[j];
				if (x % (prime * prime) == 0) {
					check = false;
					break;
				}
				if (x % prime == 0) {
					subset |= 1 << j;
				}
			}
			if (!check) {
				continue;
			}

			for (int mask = (1 << 10) - 1; mask > 0; --mask) {
				if ((mask & subset) == subset) {
					dp[mask] = (dp[mask] + static_cast<long long>(dp[mask ^ subset]) * freq[i]) % mod;
				}
			}
		}

		int ans = 0;
		for (int mask = 1; mask < 1 << 10; ++mask) {
			ans = (ans + dp[mask]) % mod;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numberOfGoodSubsets(vector<int> {1, 2, 3, 4}) << endl;
	cout << solution.numberOfGoodSubsets(vector<int> {4, 2, 3, 15}) << endl;
}

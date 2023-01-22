#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
	static const int kWidth = 5;
	static const int kWidthMask = (1 << kWidth) - 1;
public:
	int maxHappyGroups(int batchSize, vector<int>& groups) {
		vector<int> cnt(batchSize);
		for (auto &x : groups) {
			++cnt[x % batchSize];
		}

		long long start = 0;
		for (int i = batchSize - 1; i >= 1; --i){
			start = (start << kWidth) | cnt[i];
		}

		unordered_map<long long, int> memo;
		
		function<int(long long)> dfs = [&](long long mask) -> int {
			if (mask == 0) {
				return 0;
			}
			if (memo.count(mask)) {
				return memo[mask];
			}
			
			int total = 0;
			for (int i = 1; i < batchSize; ++i) {
				int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
				total += i * amount;
			}

			int best = 0;
			for (int i = 1; i < batchSize; ++i) {
				int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
				if (amount > 0) {
					int result = dfs(mask - (1LL << ((i - 1) * kWidth)));
					if ((total - i) % batchSize == 0) {
						++result;
					}
					best = max(best, result);
				}
			}

			return memo[mask] = best;
		};

		return dfs(start) + cnt[0];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maxHappyGroups(3, vector<int> {1, 2, 3, 4, 5, 6}) << endl;
	cout << solution.maxHappyGroups(4, vector<int> {1, 3, 2, 5, 2, 2, 1, 6}) << endl;
}
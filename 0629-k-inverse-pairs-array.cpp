#include <iostream>
#include <memory.h>

using namespace std;

const int MOD = 1000000007;
int f[2][1001] = { 0 };

class Solution {
public:
	int kInversePairs(int n, int k) {
		memset(f, 0, sizeof(f));
		f[0][0] = f[1][0] = 1;

		for (size_t i = 1; i <= n; ++i) {
			int curr = i & 1, prev = curr ^ 1;
			for (size_t pairCount = 1; pairCount <= k; ++pairCount) {
				f[curr][pairCount] = f[curr][pairCount - 1] - (pairCount < i ? 0 : f[prev][pairCount - i]) + f[prev][pairCount];
				if (f[curr][pairCount] >= MOD) {
					f[curr][pairCount] -= MOD;
				} else if (f[curr][pairCount] < 0) {
					f[curr][pairCount] += MOD;
				}
			}
		}
		return f[n & 1][k];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.kInversePairs(3, 0) << endl;
	cout << solution.kInversePairs(3, 1) << endl;
}

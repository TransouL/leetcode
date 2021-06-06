from typing import List


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        l = len(strs)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            ones = s.count('1')
            zeros = len(s) - ones
            for j in range(m, zeros - 1, -1):
                for k in range(n, ones - 1, -1):
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1)
        return dp[m][n]


solution = Solution()
print(solution.findMaxForm(["10", "0001", "111001", "1", "0"], 5, 3))
print(solution.findMaxForm(["10", "0", "1"], 1, 1))

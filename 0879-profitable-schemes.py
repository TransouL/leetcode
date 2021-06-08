from typing import List


class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        dp = [[1] + [0] * minProfit for _ in range(n + 1)]
        for earn, members in zip(profit, group):
            for j in range(n, members - 1, -1):
                for k in range(minProfit, -1, -1):
                    dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % (10 ** 9 + 7)
        return dp[n][minProfit]


solution = Solution()
print(solution.profitableSchemes(5, 3, [2, 2], [2, 3]))
print(solution.profitableSchemes(10, 5, [2, 3, 5], [6, 7, 8]))

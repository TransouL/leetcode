from typing import List


class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        houses = [c - 1 for c in houses]
        dp = [[[float("inf")] * target for _ in range(n)] for _ in range(m)]
        for j in range(n):
            if houses[0] == -1:
                dp[0][j][0] = cost[0][j]
            elif houses[0] == j:
                dp[0][j][0] = 0

        for i in range(1, m):
            for j in range(n):
                if houses[i] != -1 and houses[i] != j:
                    continue
                for k in range(target):
                    for j0 in range(n):
                        if j == j0:
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k])
                        else:
                            if k > 0:
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1])
                    if dp[i][j][k] != float("inf") and houses[i] == -1:
                        dp[i][j][k] += cost[i][j]
        ans = min(dp[m - 1][j][target - 1] for j in range(n))
        return ans if ans != float("inf") else -1


solution = Solution()
print(solution.minCost([0, 0, 0, 0, 0], [[1, 10], [10, 1], [10, 1], [1, 10], [5, 1]], 5, 2, 3))
print(solution.minCost([0, 2, 1, 2, 0], [[1, 10], [10, 1], [10, 1], [1, 10], [5, 1]], 5, 2, 3))
print(solution.minCost([0, 0, 0, 0, 0], [[1, 10], [10, 1], [1, 10], [10, 1], [1, 10]], 5, 2, 5))
print(solution.minCost([3, 1, 2, 3], [[1, 1, 1], [1, 1, 1], [1, 1, 1], [1, 1, 1]], 4, 3, 3))

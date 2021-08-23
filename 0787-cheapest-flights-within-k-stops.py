from typing import List

INF = 10000 * 101 + 1
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dp = [INF] * n
        ans, dp[src] = INF, 0
        for t in range(1, k + 2):
            dp_update = [INF] * n
            for from_, to, price in flights:
                dp_update[to] = min(dp_update[to], dp[from_] + price)
            dp = dp_update
            ans = min(ans, dp[dst])
        return -1 if ans == INF else ans


solution = Solution()
print(solution.findCheapestPrice(3, [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 0, 2, 1))
print(solution.findCheapestPrice(3, [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 0, 2, 0))

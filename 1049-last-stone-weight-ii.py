from typing import List


class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        neg_max = total >> 1
        dp = [True] + [False] * neg_max
        for stone in stones:
            # 对neg_max单独处理
            if neg_max >= stone and dp[neg_max - stone]:
                dp[neg_max] = True
                break

            # 从neg_max - 1开始
            for neg_can in range(neg_max - 1, stone - 1, -1):
                dp[neg_can] |= dp[neg_can - stone]

        for neg_can in range(neg_max, - 1, -1):
            if dp[neg_can]:
                return total - 2 * neg_can


solution = Solution()
print(solution.lastStoneWeightII([2, 7, 4, 1, 8, 1]))
print(solution.lastStoneWeightII([1, 2]))
print(solution.lastStoneWeightII([31, 26, 33, 21, 40]))
print(solution.lastStoneWeightII([1, 1]))
print(solution.lastStoneWeightII([91]))

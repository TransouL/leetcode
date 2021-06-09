from typing import List


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [1] + [0] * amount
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]
        return dp[amount]


solution = Solution()
print(solution.change(5, [1, 2, 5]))
print(solution.change(3, [2]))
print(solution.change(10, [10]))

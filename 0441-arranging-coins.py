class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int(pow(n * 2 + 0.25, 0.5) - 0.5)


solution = Solution()
print(solution.arrangeCoins(5))
print(solution.arrangeCoins(6))
print(solution.arrangeCoins(8))

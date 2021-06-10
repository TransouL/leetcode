class Solution:
    def __init__(self):
        self.squares = [0] * 100
        for i in range(1, 101):
            self.squares[i - 1] = i * i

    def numSquares(self, n: int) -> int:
        dp = list(range(n + 1))
        for square in self.squares:
            for total in range(square, n + 1):
                dp[total] = min(dp[total], dp[total - square] + 1)
        return dp[n]


solution = Solution()
print(solution.numSquares(12))
print(solution.numSquares(13))

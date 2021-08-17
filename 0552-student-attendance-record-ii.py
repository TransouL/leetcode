MOD = 1000000007


class Solution:
    def checkRecord(self, n: int) -> int:
        dp = [0, 1, 0, 0, 1, 1]
        for i in range(n - 1):
            dp = [dp[4], dp[5], dp[0], dp[1], sum(dp) % MOD, (dp[1] + dp[3] + dp[5]) % MOD]
        return sum(dp) % MOD


solution = Solution()
print(solution.checkRecord(1))
print(solution.checkRecord(2))
print(solution.checkRecord(10101))
print(solution.checkRecord(1000000))

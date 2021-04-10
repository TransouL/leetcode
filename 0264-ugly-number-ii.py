class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n < 7:
            return n
        dp = [0] * (n + 1)
        dp[1] = 1
        p2 = p3 = p5 = 1
        for i in range(2, n + 1):
            num2, num3, num5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(num2, num3, num5)
            if dp[i] == num2:
                p2 += 1
            if dp[i] == num3:
                p3 += 1
            if dp[i] == num5:
                p5 += 1

        return dp[n]


solution = Solution()
print(solution.nthUglyNumber(10))  # 12
print(solution.nthUglyNumber(1))  # 1
print(solution.nthUglyNumber(100))  # 1536
print(solution.nthUglyNumber(1000))  # 51200000
print(solution.nthUglyNumber(1689))  # 2109375000
print(solution.nthUglyNumber(1690))  # 2123366400

class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        a, b, c, d = 1, 1, 2, 2
        for i in range(4, n + 1):
            d = a + b + c
            a, b, c = b, c, d
        return d


solution = Solution()
print(solution.tribonacci(4))
print(solution.tribonacci(25))

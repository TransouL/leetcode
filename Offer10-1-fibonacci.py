class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        a, b, c = 0, 1, 1
        for i in range(3, n + 1):
            a, b, c = b, c, (b + c) % 1000000007
        return c


solution = Solution()
print(solution.fib(5))
print(solution.fib(100))

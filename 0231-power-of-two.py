class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0
        # return 0 < n == n & -n
        # return n > 0 and 2**30 % n == 0


solution = Solution()
print(solution.isPowerOfTwo(1))
print(solution.isPowerOfTwo(4))
print(solution.isPowerOfTwo(3))
print(solution.isPowerOfTwo(5))
print(solution.isPowerOfTwo(0))
print(solution.isPowerOfTwo(-2))

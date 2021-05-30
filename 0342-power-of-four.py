class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 and n & 0xAAAAAAAA == 0
        # return n > 0 and n & (n - 1) == 0 and n % 3 == 1
        # return n in (1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824)


solution = Solution()
print(solution.isPowerOfFour(16))
print(solution.isPowerOfFour(1))
print(solution.isPowerOfFour(5))
print(solution.isPowerOfFour(8))
print(solution.isPowerOfFour(0))
print(solution.isPowerOfFour(-4))

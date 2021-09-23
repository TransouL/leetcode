class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0


solution = Solution()
print(solution.isPowerOfThree(27))
print(solution.isPowerOfThree(0))
print(solution.isPowerOfThree(9))
print(solution.isPowerOfThree(45))

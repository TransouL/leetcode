class Solution:
    def canWinNim(self, n: int) -> bool:
        return n & 3 != 0


solution = Solution()
print(solution.canWinNim(4))
print(solution.canWinNim(1))
print(solution.canWinNim(2))
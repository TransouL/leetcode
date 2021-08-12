class Solution:
    def countDigitOne(self, n: int) -> int:
        ans, mulk = 0, 1
        while n >= mulk:
            ans += (n // (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0), mulk)
            mulk *= 10
        return ans


solution = Solution()
print(solution.countDigitOne(13))
print(solution.countDigitOne(0))

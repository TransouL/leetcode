class Solution:
    def maxScore(self, s: str) -> int:
        tot0, tot1 = 0, 0
        curr, maxScore, max0, max1 = 0, -2, 0, 0
        for ch in s[:-1]:
            if ch == '0':
                tot0 += 1
                curr += 1
            else:
                tot1 += 1
                curr -= 1
            if curr > maxScore:
                maxScore = curr
                max0, max1 = tot0, tot1
        if s[-1] == '1':
            tot1 += 1
        return max0 + tot1 - max1


solution = Solution()
print(solution.maxScore("011101"))
print(solution.maxScore("00111"))
print(solution.maxScore("1111"))
print(solution.maxScore("0000"))

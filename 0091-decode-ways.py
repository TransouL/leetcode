class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        a, b, c = 0, 1, 0
        for i in range(n):
            c = 0
            if s[i] != '0':
                c += b
            if i > 0 and s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                c += a
            a, b = b, c
        return c


# solution = Solution()
# print(solution.numDecodings("12"))
# print(solution.numDecodings("226"))
# print(solution.numDecodings("0"))
# print(solution.numDecodings("06"))
# print(solution.numDecodings("1"))

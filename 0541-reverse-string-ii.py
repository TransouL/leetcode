class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        sl = list(s)
        for i in range(0, len(s), k * 2):
            sl[i:i + k] = reversed(sl[i:i + k])
        return "".join(sl)


solution = Solution()
print(solution.reverseStr("abcdefg", 2))
print(solution.reverseStr("abcdefghijklmn", 3))
print(solution.reverseStr("ab", 3))

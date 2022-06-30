class Solution:
    def greatestLetter(self, s: str) -> str:
        flag1, flag2 = [False] * 26, [False] * 26
        for ch in s:
            if ch.isupper():
                flag1[ord(ch) - ord('A')] = True
            else:
                flag2[ord(ch) - ord('a')] = True
        for i in range(25, -1, -1):
            if flag1[i] and flag2[i]:
                return chr(ord('A') + i)
        return ""


solution = Solution()
print(solution.greatestLetter("lEeTcOdE"))
print(solution.greatestLetter("arRAzFif"))
print(solution.greatestLetter("AbCdEfGhIjK"))

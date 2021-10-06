class Solution:
    def countSegments(self, s: str) -> int:
        ans, isBlank = 0, True
        for ch in s:
            if isBlank:
                if ch != ' ':
                    ans += 1
                    isBlank = False
            else:
                if ch == ' ':
                    isBlank = True
        return ans


solution = Solution()
print(solution.countSegments("  Hello,   my  name is John  "))

class Solution:
    def checkValidString(self, s: str) -> bool:
        minCount = maxCount = 0
        n = len(s)
        for i, ch in enumerate(s):
            if ch == '(':
                minCount += 1
                maxCount += 1
            elif ch == ')':
                minCount = max(minCount - 1, 0)
                maxCount -= 1
                if maxCount < 0:
                    return False
            else:
                minCount = max(minCount - 1, 0)
                maxCount += 1

        return minCount == 0


solution = Solution()
print(solution.checkValidString("()"))
print(solution.checkValidString("(*)"))
print(solution.checkValidString("(*))"))

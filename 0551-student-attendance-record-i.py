class Solution:
    def checkRecord(self, s: str) -> bool:
        allA = contL = 0
        for ch in s:
            if ch == 'L':
                contL += 1
                if contL == 3:
                    return False
            elif ch == 'A':
                contL = 0
                allA += 1
                if allA == 2:
                    return False
            else:
                contL = 0
        return True


solution = Solution()
print(solution.checkRecord("PPALLP"))
print(solution.checkRecord("PPALLL"))
print(solution.checkRecord("LLALPP"))

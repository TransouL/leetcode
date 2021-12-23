class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans, multiple = 0, 1
        for i in range(len(columnTitle) - 1, -1, -1):
            k = ord(columnTitle[i]) - ord('A') + 1
            ans += k * multiple
            multiple *= 26
        return ans


solution = Solution()
print(solution.titleToNumber("A"))
print(solution.titleToNumber("AB"))
print(solution.titleToNumber("ZY"))

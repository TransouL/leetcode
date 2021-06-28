class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ""
        while columnNumber:
            last_offset_from_A = (columnNumber - 1) % 26
            ans = chr(ord('A') + last_offset_from_A) + ans
            columnNumber = (columnNumber - (last_offset_from_A + 1)) // 26
        return ans


solution = Solution()
print(solution.convertToTitle(1))
print(solution.convertToTitle(28))
print(solution.convertToTitle(701))


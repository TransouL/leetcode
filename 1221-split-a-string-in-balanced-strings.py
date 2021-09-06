class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans, curr_ch, curr_count = 0, 'L', 0
        for ch in s:
            if curr_count == 0:
                curr_ch, curr_count = ch, 1
            else:
                if curr_ch == ch:
                    curr_count += 1
                else:
                    curr_count -= 1
                    if curr_count == 0:
                        ans += 1
        return ans


solution = Solution()
print(solution.balancedStringSplit("RLRRLLRLRL"))
print(solution.balancedStringSplit("RLLLLRRRLR"))
print(solution.balancedStringSplit("LLLLRRRR"))
print(solution.balancedStringSplit("RLRRRLLRLL"))

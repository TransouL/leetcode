from typing import List


class Solution:
    def maximumTime(self, time: str) -> str:
        chars = list(time)
        if chars[0] == '?':
            if '4' <= chars[1] <= '9':
                chars[0] = '1'
            else:
                chars[0] = '2'
        if chars[1] == '?':
            if chars[0] == '2':
                chars[1] = '3'
            else:
                chars[1] = '9'
        if chars[3] == '?':
            chars[3] = '5'
        if chars[4] == '?':
            chars[4] = '9'

        return "".join(chars)


solution = Solution()
print(solution.maximumTime("2?:?0"))
print(solution.maximumTime("0?:3?"))
print(solution.maximumTime("1?:22"))
print(solution.maximumTime("?5:??"))
print(solution.maximumTime("?4:??"))
print(solution.maximumTime("??:??"))

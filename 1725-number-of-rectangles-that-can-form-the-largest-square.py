from typing import List


class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        maxLen, ans = 0, 0
        for l, w in rectangles:
            square = min(l, w)
            if square > maxLen:
                maxLen, ans = square, 1
            elif square == maxLen:
                ans += 1
        return ans


solution = Solution()
print(solution.countGoodRectangles([[5, 8], [3, 9], [5, 12], [16, 5]]))
print(solution.countGoodRectangles([[2, 3], [3, 7], [4, 3], [3, 7]]))

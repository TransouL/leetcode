from typing import List


class Solution:
    def countElements(self, nums: List[int]) -> int:
        min_, max_ = min(nums), max(nums)
        return len([x for x in nums if min_ < x < max_])


solution = Solution()
print(solution.countElements([11, 7, 2, 15]))
print(solution.countElements([-3, 3, 3, 90]))

from typing import List


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        ans, sum_ = 0, 0
        for num in nums:
            sum_ += num
            ans = min(ans, sum_)
        return -ans + 1


solution = Solution()
print(solution.minStartValue([-3, 2, -3, 4, 2]))
print(solution.minStartValue([1, 2]))
print(solution.minStartValue([1, -2, -3]))

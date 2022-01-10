from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0

        size = len(nums)
        if size == 1:
            return nums[0]

        prev, curr = nums[0], max(nums[0], nums[1])
        for i in range(2, size):
            prev, curr = curr, max(prev + nums[i], curr)

        return curr


solution = Solution()
print(solution.rob([1, 2, 3, 1]))
print(solution.rob([2, 7, 9, 3, 1]))

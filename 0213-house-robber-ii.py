from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        def robRange(start: int, end: int) -> int:
            prev, curr = nums[start], max(nums[start], nums[start + 1])
            for i in range(start + 2, end + 1):
                prev, curr = curr, max(prev + nums[i], curr)
            return curr

        if not nums:
            return 0
        size = len(nums)
        if size <= 3:
            return max(nums)
        return max(robRange(0, size - 2), robRange(1, size -1))


solution = Solution()
print(solution.rob([2,3,2]))
print(solution.rob([1, 2, 3, 1]))
print(solution.rob([2, 7, 9, 3, 1]))

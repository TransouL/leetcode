# from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if not nums:
            return 0
        n = len(nums)

        left, right = 0, n - 1
        while left <= right:
            if nums[left] == val:
                nums[left] = nums[right]
                right -= 1
            else:
                left += 1

        return left


# solution = Solution()
# nums = [3, 2, 2, 3]
# print(solution.removeElement(nums, 3))
# print(nums)
# 
# nums = [0, 1, 2, 2, 3, 0, 4, 2]
# print(solution.removeElement(nums, 2))
# print(nums)

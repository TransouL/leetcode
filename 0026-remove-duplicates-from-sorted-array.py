from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        if n <= 1:
            return n

        slow, fast = 1, 1
        while fast < n:
            if nums[slow - 1] != nums[fast]:  # 这里也可以写： if nums[fast - 1] != nums[fast]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1

        return slow


solution = Solution()
nums = [1, 1, 1, 2, 2, 3]
print(solution.removeDuplicates(nums))
print(nums)
nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]
print(solution.removeDuplicates(nums))
print(nums)
nums = [-1, -1, -1, 2, 3, 3, 3, 3, 3]
print(solution.removeDuplicates(nums))
print(nums)
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
print(solution.removeDuplicates(nums))
print(nums)
nums = [1, 1]
print(solution.removeDuplicates(nums))
print(nums)
nums = []
print(solution.removeDuplicates(nums))
print(nums)

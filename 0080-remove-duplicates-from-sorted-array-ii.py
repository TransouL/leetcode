# from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        if n <= 2:
            return n

        curr, count = nums[0], 1
        for i in nums[1:]:
            if i == curr:
                if count < 2:
                    count += 1
                else:
                    nums.remove(i)
            else:
                curr, count = i, 1

        return len(nums)


# solution = Solution()
# nums = [1, 1, 1, 2, 2, 3]
# print(solution.removeDuplicates(nums))
# print(nums)
# nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]
# print(solution.removeDuplicates(nums))
# print(nums)
# nums = [1, 2]
# print(solution.removeDuplicates(nums))
# print(nums)
# nums = []
# print(solution.removeDuplicates(nums))
# print(nums)

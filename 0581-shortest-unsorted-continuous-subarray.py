from typing import List


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        low_index = high_index = -1
        low_value = nums[-1]
        high_value = nums[0]
        for i in range(1, n):
            if nums[n - 1 - i] > low_value:
                low_index = n - 1 - i
            else:
                low_value = nums[n - 1 - i]

            if nums[i] < high_value:
                high_index = i
            else:
                high_value = nums[i]

        return 0 if low_index == -1 else high_index - low_index + 1


solution = Solution()
print(solution.findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15]))
print(solution.findUnsortedSubarray([1, 2, 3, 4]))

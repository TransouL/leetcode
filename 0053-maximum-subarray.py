from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result, sum_curr = nums[0], nums[0]
        for n in nums[1:]:
            if sum_curr < 0:
                sum_curr = 0
            sum_curr += n
            result = max(result, sum_curr)
        return result


solution = Solution()
print(solution.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
print(solution.maxSubArray([5, 4, -1, 7, 8]))
print(solution.maxSubArray([-1]))

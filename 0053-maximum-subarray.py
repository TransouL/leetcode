from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, curr_sum = nums[0], 0
        for num in nums:
            curr_sum = max(num, curr_sum + num)
            ans = max(ans, curr_sum)
        return ans


solution = Solution()
print(solution.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
print(solution.maxSubArray([5, 4, -1, 7, 8]))
print(solution.maxSubArray([-1]))

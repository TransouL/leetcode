from typing import List


class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        L = 0
        window_sum = 0
        for R in range(n):
            if R > 0:
                window_sum += nums[R - 1]
            while window_sum + k < nums[R] * (R - L):
                window_sum -= nums[L]
                L += 1
            ans = max(ans, R - L + 1)
        return ans


solution = Solution()
print(solution.maxFrequency([1, 2, 4], 5))
print(solution.maxFrequency([1, 4, 8, 13], 5))
print(solution.maxFrequency([3, 9, 6], 2))

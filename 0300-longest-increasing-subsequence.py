from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if dp[j] >= dp[i] and nums[j] < nums[i]:
                    dp[i] = dp[j] + 1
        return max(dp)


solution = Solution()
print(solution.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
print(solution.lengthOfLIS([0, 1, 0, 3, 2, 3]))
print(solution.lengthOfLIS([7, 7, 7, 7, 7, 7, 7]))

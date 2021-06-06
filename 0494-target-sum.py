from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        sum_all = sum(nums)
        diff = sum_all - target
        if diff < 0 or diff & 1 != 0:
            return 0
        neg = diff >> 1
        dp = [1] + [0] * neg
        for num in nums:
            for j in range(neg, num - 1, -1):
                dp[j] += dp[j - num]
        return dp[neg]


solution = Solution()
print(solution.findTargetSumWays([1, 1, 1, 1, 1], 3))
print(solution.findTargetSumWays([1], 1))
print(solution.findTargetSumWays([31, 4, 45, 3, 44, 49, 28, 6, 22, 24, 40, 25, 13, 46, 17, 10, 2, 38, 25, 15], 25))

from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        dp = [1] + [0] * target
        for i in range(1, target + 1):
            for n in nums:
                if n <= i:
                    dp[i] += dp[i - n]
        return dp[target]


solution = Solution()
print(solution.combinationSum4([1, 2, 3], 4))
print(solution.combinationSum4([9], 3))
print(solution.combinationSum4([], 1))

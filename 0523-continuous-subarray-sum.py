from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < 2:
            return False
        memo, rem = {0: -1}, 0
        for i in range(n):
            rem = (rem + nums[i]) % k
            if rem in memo:
                if i - memo[rem] >= 2:
                    return True
            else:
                memo[rem] = i
        return False


solution = Solution()
print(solution.checkSubarraySum([23, 2, 4, 6, 7], 6))
print(solution.checkSubarraySum([23, 2, 6, 4, 7], 6))
print(solution.checkSubarraySum([23, 2, 6, 4, 7], 13))

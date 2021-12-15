from typing import List
from collections import Counter


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans, preSum, counter = 0, 0, Counter([0])
        for num in nums:
            preSum += num
            if preSum - k in counter:
                ans += counter[preSum - k]
            counter[preSum] += 1
        return ans


solution = Solution()
print(solution.subarraySum([1, 1, 1], 2))

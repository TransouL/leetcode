from collections import defaultdict
from typing import List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        f = [defaultdict(int) for _ in nums]
        for i, x in enumerate(nums):
            for j in range(i):
                d = x - nums[j]
                cnt = f[j][d]
                f[i][d] += cnt + 1
                ans += cnt
        return ans


solution = Solution()
print(solution.numberOfArithmeticSlices([2, 4, 6, 8, 10]))
print(solution.numberOfArithmeticSlices([7, 7, 7, 7, 7]))

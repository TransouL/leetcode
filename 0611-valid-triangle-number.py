import bisect
from typing import List


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        start = 0
        while start < n - 2 and nums[start] == 0:
            start += 1

        ans = 0
        memo = {}
        for ai in range(start, n - 2):
            for bi in range(ai + 1, n - 1):
                aplusb = nums[ai] + nums[bi]
                if aplusb not in memo:
                    c_can = bisect.bisect_left(nums, aplusb, lo=bi + 1) - 1
                    memo[aplusb] = c_can
                ans += memo[aplusb] - bi
        return ans


solution = Solution()
print(solution.triangleNumber([2, 2, 3, 4]))
from typing import List


class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n < 2:
            return n
        nums = [0, 1, 1]
        half = (n + 1) // 2
        for i in range(2, half + 1):
            nums.append(nums[i] + nums[i - 1])
            nums.append(nums[i])
        return max(nums)


solution = Solution()
print(solution.getMaximumGenerated(0))
print(solution.getMaximumGenerated(7))
print(solution.getMaximumGenerated(100))

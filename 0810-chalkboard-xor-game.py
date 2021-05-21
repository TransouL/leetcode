from typing import List


class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        if len(nums) & 1 == 0:
            return True
        xor = 0
        for i in nums:
            xor ^= i
        return xor == 0


solution = Solution()
print(solution.xorGame([1, 1, 2]))
print(solution.xorGame([2, 2, 2, 3]))

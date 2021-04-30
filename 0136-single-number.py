from functools import reduce
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x ^ y, nums)


solution = Solution()
print(solution.singleNumber([2, 2, 1]))
print(solution.singleNumber([4, 1, 2, 1, 2]))
print(solution.singleNumber([1, 2147483647, 1]))
print(solution.singleNumber([2147483647, 1, 2147483647]))
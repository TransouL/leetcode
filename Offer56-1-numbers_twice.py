from functools import reduce
from typing import List


class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        xorall = reduce(lambda x, y: x ^ y, nums)
        div = 1
        while div & xorall == 0:
            div <<= 1
        a = b = 0
        for n in nums:
            if n & div:
                a ^= n
            else:
                b ^= n
        return [a, b]


solution = Solution()
print(solution.singleNumbers([4, 1, 4, 6]))
print(solution.singleNumbers([1, 2, 10, 4, 1, 4, 3, 3]))

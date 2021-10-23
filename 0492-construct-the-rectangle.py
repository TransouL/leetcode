from math import sqrt
from typing import List


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        sqrt_ = int(sqrt(area))
        for W in range(sqrt_, 0, -1):
            if area % W == 0:
                return [area // W, W]


solution = Solution()
print(solution.constructRectangle(4))
print(solution.constructRectangle(37))
print(solution.constructRectangle(122122))
print(solution.constructRectangle(10000000))

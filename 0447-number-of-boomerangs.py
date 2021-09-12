from collections import defaultdict
from typing import List


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for xi, yi in points:
            cnt = defaultdict(int)
            for xj, yj in points:
                cnt[(xi - xj) ** 2 + (yi - yj) ** 2] += 1
            for disCount in cnt.values():
                ans += disCount * (disCount - 1)
        return ans


solution = Solution()
print(solution.numberOfBoomerangs([[0, 0], [1, 0], [2, 0]]))
print(solution.numberOfBoomerangs([[1, 1], [2, 2], [3, 3]]))
print(solution.numberOfBoomerangs([[1, 1]]))

from functools import lru_cache
from typing import List
from bisect import bisect_left


def index(a: List[int], x) -> int:
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return -1


class Solution:
    @lru_cache(None)
    def dfs(self, current: int, last_step: int, target: int) -> bool:
        if current > target:
            return False
        if current == target:
            return True
        result1, result2, result3 = False, False, False
        if index(self.stones, current + last_step + 1) != -1:
            result1 = self.dfs(current + last_step + 1, last_step + 1, target)
        if index(self.stones, current + last_step) != -1:
            result2 = self.dfs(current + last_step, last_step, target)
        if last_step > 1 and index(self.stones, current + last_step - 1) != -1:
            result3 = self.dfs(current + last_step - 1, last_step - 1, target)
        return result1 or result2 or result3

    def canCross(self, stones: List[int]) -> bool:
        if stones[1] - stones[0] > 1:
            return False
        self.stones = stones
        return self.dfs(stones[1], 1, stones[-1])


solution = Solution()
print(solution.canCross([0, 1, 3, 5, 6, 8, 12, 17]))
print(solution.canCross([0, 1, 2, 3, 4, 8, 9, 11]))
print(solution.canCross([0, 2]))
print(solution.canCross([0, 1, 2147483647]))


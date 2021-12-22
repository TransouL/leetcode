import bisect
from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while len(stones) > 1:
            y, x = stones.pop(), stones.pop()
            if y != x:
                remain = y - x
                index = bisect.bisect_left(stones, remain)
                stones.insert(index, remain)
        return stones[0] if len(stones) == 1 else 0


solution = Solution()
print(solution.lastStoneWeight([2, 7, 4, 1, 8, 1]))
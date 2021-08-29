import bisect
import random
from itertools import accumulate
from typing import List


class Solution:

    def __init__(self, w: List[int]):
        self.pre = list(accumulate(w))
        self.total = self.pre[-1]

    def pickIndex(self) -> int:
        x = random.randint(1, self.total)
        return bisect.bisect_left(self.pre, x)


solution = Solution([1, 3])
for i in range(10):
    print(solution.pickIndex())

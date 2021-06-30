from collections import defaultdict
from typing import List


class Solution:
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        mapping = defaultdict(set)
        for r in relation:
            mapping[r[0]].add(r[1])
        curr = [0]
        while k > 1:
            next = []
            for i in curr:
                next.extend((mapping[i]))
            curr = next
            k -= 1
        ans = 0
        for i in curr:
            if n - 1 in mapping[i]:
                ans += 1
        return ans


solution = Solution()
print(solution.numWays(5, [[0, 2], [2, 1], [3, 4], [2, 3], [1, 4], [2, 0], [0, 4]], 3))
print(solution.numWays(3, [[0, 2], [2, 1]], 2))

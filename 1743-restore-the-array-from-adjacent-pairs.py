from collections import defaultdict
from typing import List


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        n = len(adjacentPairs)
        if n == 1:
            return adjacentPairs[0]

        stat = defaultdict(list)
        for i, j in adjacentPairs:
            stat[i].append(j)
            stat[j].append(i)

        ans = [0] * (n + 1)
        for key, adjacents in stat.items():
            if len(adjacents) == 1:
                ans[0] = key
                ans[1] = stat[key][0]
                break

        for i in range(1, n):
            ans[i + 1] = stat[ans[i]][1] if stat[ans[i]][0] == ans[i - 1] else stat[ans[i]][0]

        return ans


solution = Solution()
print(solution.restoreArray([[2, 1], [3, 4], [3, 2]]))
print(solution.restoreArray([[4, -2], [1, 4], [-3, 1]]))
print(solution.restoreArray([[100000, -100000]]))

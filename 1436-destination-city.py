from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        srcs = {path[0] for path in paths}
        for path in paths:
            if path[1] not in srcs:
                return path[1]


solution = Solution()
print(solution.destCity([["London", "New York"], ["New York", "Lima"], ["Lima", "Sao Paulo"]]))
print(solution.destCity([["B", "C"], ["D", "B"], ["C", "A"]]))

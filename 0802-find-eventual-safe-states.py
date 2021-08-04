from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        def isSafe(x: int) -> bool:
            if color[x] > 0:
                return color[x] == 2
            color[x] = 1
            for y in graph[x]:
                if not isSafe(y):
                    return False
            color[x] = 2
            return True

        n = len(graph)
        color = [0] * n
        return [i for i in range(n) if isSafe(i)]



solution = Solution()
print(solution.eventualSafeNodes([[1, 2], [2, 3], [5], [0], [5], [], []]))
print(solution.eventualSafeNodes([[1, 2, 3, 4], [1, 2], [3, 4], [0, 4], []]))
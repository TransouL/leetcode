from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        path = [0] * n

        def dfs(steps: int, last: int) -> None:
            if last == n - 1:
                ans.append(path[:steps])
            else:
                for node in graph[last]:
                    path[steps] = node
                    dfs(steps + 1, node)

        dfs(1, 0)
        return ans


solution = Solution()
print(solution.allPathsSourceTarget([[1, 2], [3], [3], []]))
print(solution.allPathsSourceTarget([[4, 3, 1], [3, 2, 4], [3], [4], []]))
print(solution.allPathsSourceTarget([[1], []]))
print(solution.allPathsSourceTarget([[1, 2, 3], [2], [3], []]))
print(solution.allPathsSourceTarget([[1, 3], [2], [3], []]))

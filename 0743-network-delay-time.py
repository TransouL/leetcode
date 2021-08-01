from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        g = [[10001] * n for _ in range(n)]
        for u, v, w in times:
            g[u - 1][v - 1] = w

        dist, visited = g[k - 1], [False] * n
        dist[k - 1], visited[k - 1] = 0, True
        for _ in range(n):
            min_node = -1
            for node, flag in enumerate(visited):
                if not flag and (min_node == -1 or dist[node] < dist[min_node]):
                    min_node = node

            if dist[min_node] == 10001:
                return -1
            visited[min_node] = True
            for node, time in enumerate(g[min_node]):
                dist[node] = min(dist[node], dist[min_node] + time)

        return max(dist)


solution = Solution()
print(solution.networkDelayTime([[2, 1, 1], [2, 3, 1], [3, 4, 1]], 4, 2))
print(solution.networkDelayTime([[1, 2, 1]], 2, 1))
print(solution.networkDelayTime([[1, 2, 1]], 2, 2))

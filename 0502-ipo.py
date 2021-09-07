import heapq
from typing import List


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        if w >= max(capital):
            return w + sum(heapq.nlargest(k, profits))

        n = len(profits)
        curr = 0
        tasks = [(capital[i], profits[i]) for i in range(n)]
        tasks.sort(key=lambda x: x[0])

        pq = []
        for _ in range(k):
            while curr < n and tasks[curr][0] <= w:
                heapq.heappush(pq, -tasks[curr][1])
                curr += 1
            if pq:
                w -= heapq.heappop(pq)
            else:
                break

        return w


solution = Solution()
print(solution.findMaximizedCapital(2, 0, [1, 2, 3], [0, 1, 1]))

import heapq
from typing import List


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        power = []
        for i in range(m):
            l, r = 0, n - 1
            while l < r:
                mid = (l + r + 1) // 2
                if mat[i][mid] == 0:
                    r = mid - 1
                else:
                    l = mid
            power.append((0 if mat[i][l] == 0 else l + 1, i))

        heapq.heapify(power)
        ans = [0] * k
        for i in range(k):
            ans[i] = heapq.heappop(power)[1]
        return ans


solution = Solution()
print(solution.kWeakestRows([[1, 1, 0, 0, 0],
                             [1, 1, 1, 1, 0],
                             [1, 0, 0, 0, 0],
                             [1, 1, 0, 0, 0],
                             [1, 1, 1, 1, 1]], 3))
print(solution.kWeakestRows([[1, 0, 0, 0],
                             [1, 1, 1, 1],
                             [1, 0, 0, 0],
                             [1, 0, 0, 0]], 2))
print(solution.kWeakestRows([[1, 0], [0, 0], [1, 0]], 2))

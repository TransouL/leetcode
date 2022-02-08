from collections import Counter
from typing import List


class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        lamps = set([tuple(lamp) for lamp in lamps])
        row, col, diagonal, antiDiagonal = Counter(), Counter(), Counter(), Counter()
        for rowl, coll in lamps:
            row[rowl] += 1
            col[coll] += 1
            diagonal[rowl - coll] += 1
            antiDiagonal[rowl + coll] += 1

        ans = [0] * len(queries)
        for i, (rowq, colq) in enumerate(queries):
            if row[rowq] or col[colq] or diagonal[rowq - colq] or antiDiagonal[rowq + colq]:
                ans[i] = 1
            for nx, ny in ((rowq, colq), (rowq, colq + 1), (rowq, colq - 1), (rowq + 1, colq), (rowq - 1, colq),
                           (rowq + 1, colq + 1), (rowq + 1, colq - 1), (rowq - 1, colq + 1), (rowq - 1, colq - 1)):
                if 0 <= nx < n and 0 <= ny < n and (nx, ny) in lamps:
                    lamps.remove((nx, ny))
                    row[nx] -= 1
                    col[ny] -= 1
                    diagonal[nx - ny] -= 1
                    antiDiagonal[nx + ny] -= 1
        return ans


solution = Solution()
print(solution.gridIllumination(n=5, lamps=[[0, 0], [4, 4]], queries=[[1, 1], [1, 0]]))
print(solution.gridIllumination(n=5, lamps=[[0, 0], [4, 4]], queries=[[1, 1], [1, 1]]))
print(solution.gridIllumination(n=5, lamps=[[0, 0], [0, 4]], queries=[[0, 4], [0, 1], [1, 4]]))
print(solution.gridIllumination(n=6, lamps=[[1, 1]], queries=[[2, 0], [1, 0]]))

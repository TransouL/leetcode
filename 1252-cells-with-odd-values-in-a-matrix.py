from typing import List


class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        cells = [[False] * n for _ in range(m)]
        rows, cols = set(), set()
        for r, c in indices:
            if r in rows:
                rows.remove(r)
            else:
                rows.add(r)
            if c in cols:
                cols.remove(c)
            else:
                cols.add(c)
        for r in rows:
            for c in range(n):
                if c not in cols:
                    cells[r][c] = True
        for c in cols:
            for r in range(m):
                if r not in rows:
                    cells[r][c] = True
        return sum(map(sum, cells))


solution = Solution()
print(solution.oddCells(m=2, n=3, indices=[[0, 1], [1, 1]]))
print(solution.oddCells(m=2, n=2, indices=[[1, 1], [0, 0]]))
print(solution.oddCells(m=48, n=37, indices=[[40, 5]]))

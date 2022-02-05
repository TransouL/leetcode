from typing import List


class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        def dfs(x: int, y: int, curr: int) -> None:
            nonlocal ans
            if grid[x][y] == 0:
                ans = max(ans, curr)
                return
            tmp, grid[x][y] = grid[x][y], 0
            for nx, ny in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                if 0 <= nx < m and 0 <= ny < n:
                    dfs(nx, ny, curr + tmp)
            grid[x][y] = tmp

        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    dfs(i, j, 0)
        return ans


solution = Solution()
print(solution.getMaximumGold([[0, 6, 0], [5, 8, 7], [0, 9, 0]]))
print(solution.getMaximumGold([[1, 0, 7], [2, 0, 6], [3, 4, 5], [0, 3, 0], [9, 0, 20]]))

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        if maxMove == 0:
            return 0

        def dp(x: int, y: int, steps: int) -> int:
            if counts[x][y][steps - 1] != -1:
                return counts[x][y][steps - 1]

            if steps == 1:
                counts[x][y][0] = 0
                if x != 0 and x != m - 1 and y != 0 and y != n - 1:
                    return 0
                else:
                    for d in range(4):
                        if not (0 <= x - dx[d] < m and 0 <= y - dy[d] < n):
                            counts[x][y][0] += 1
                    return counts[x][y][0]

            count = dp(x, y, 1)
            for d in range(4):
                if 0 <= x - dx[d] < m and 0 <= y - dy[d] < n:
                    count += dp(x - dx[d], y - dy[d], steps - 1)
            counts[x][y][steps - 1] = count
            return count

        counts = [[[-1] * maxMove for _ in range(n)] for _ in range(m)]
        return dp(startRow, startColumn, maxMove) % 1000000007


solution = Solution()
print(solution.findPaths(2, 2, 2, 0, 0))
print(solution.findPaths(1, 3, 3, 0, 1))
print(solution.findPaths(10, 10, 0, 5, 5))  # 0
print(solution.findPaths(1, 2, 50, 0, 0))  # 150

from typing import List


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        rows = len(wall)
        lines = {-1: 0}
        for row in wall:
            curr = -1
            for brick in row[:-1]:
                curr += brick
                if curr in lines:
                    lines[curr] += 1
                else:
                    lines[curr] = 1
        return rows - max(lines.values())


solution = Solution()
print(solution.leastBricks([[1, 2, 2, 1], [3, 1, 2], [1, 3, 2], [2, 4], [3, 1, 2], [1, 3, 1, 1]]))
print(solution.leastBricks([[1], [1], [1]]))
print(solution.leastBricks([[100000000], [100000000], [100000000]]))
print(solution.leastBricks([[1, 1, 2147483647], [1, 2147483647, 1], [2147483647, 1, 1]]))

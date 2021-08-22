from typing import List


class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        player_dis = abs(target[0]) + abs(target[1])
        for gx, gy in ghosts:
            if (abs(gx - target[0]) + abs(gy - target[1])) <= player_dis:
                return False
        return True


solution = Solution()
print(solution.escapeGhosts([[1, 0], [0, 3]], [0, 1]))
print(solution.escapeGhosts([[1, 0]], [2, 0]))
print(solution.escapeGhosts([[2, 0]], [1, 0]))
print(solution.escapeGhosts([[5, 0], [-10, -2], [0, -5], [-2, -2], [-7, 1]], [7, 7]))

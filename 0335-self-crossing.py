from typing import List


class Solution:
    def isSelfCrossing(self, distance: List[int]) -> bool:
        n = len(distance)

        if n > 4 and distance[3] == distance[1] and distance[4] >= distance[2] - distance[0]:
            return True
        for i in range(3, n):
            if distance[i] >= distance[i - 2] and distance[i - 1] <= distance[i - 3]:
                return True
            if i >= 5 and distance[i - 3] - distance[i - 5] <= distance[i - 1] <= distance[i - 3] \
                    and distance[i] >= distance[i - 2] - distance[i - 4] and distance[i - 2] > distance[i - 4]:
                return True
        return False


solution = Solution()
print(solution.isSelfCrossing([2, 1, 1, 2]))
print(solution.isSelfCrossing([1, 2, 3, 4]))
print(solution.isSelfCrossing([1, 1, 1, 1]))

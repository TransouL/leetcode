from typing import List


class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        sum_ = sum(machines)
        n = len(machines)
        if sum_ % n != 0:
            return -1
        avg = sum_ // n
        ans, totalMove = 0, 0
        for machine in machines:
            toMove = machine - avg
            totalMove += toMove
            ans = max(ans, abs(totalMove), toMove)
        return ans


solution = Solution()
print(solution.findMinMoves([1, 0, 5]))
print(solution.findMinMoves([0, 3, 0]))
print(solution.findMinMoves([0, 2, 0]))

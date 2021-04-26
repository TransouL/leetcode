from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        left, right = max(weights), sum(weights)
        while left < right:
            mid = (left + right) // 2
            need, curr = 1, 0
            for weight in weights:
                if curr + weight > mid:
                    need += 1
                    curr = 0
                curr += weight

            if need <= D:
                right = mid
            else:
                left = mid + 1

        return left


solution = Solution()
print(solution.shipWithinDays([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5))
print(solution.shipWithinDays([3, 2, 2, 4, 1, 4], 3))
print(solution.shipWithinDays([1, 2, 3, 1, 1], 4))

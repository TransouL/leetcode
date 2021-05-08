from typing import List


class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < k * m:
            return -1

        def check(days: int) -> bool:
            flowers, bouquets = 0, 0
            for i, bloom in enumerate(bloomDay):
                if bloomDay[i] <= days:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        if bouquets == m:
                            return True
                        flowers = 0
                else:
                    flowers = 0
            return False

        l, r = 1, max(bloomDay)
        while l < r:
            mid = (l + r) // 2
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l


solution = Solution()
print(solution.minDays([1, 10, 3, 10, 2], 3, 1))
print(solution.minDays([1, 10, 3, 10, 2], 3, 2))
print(solution.minDays([7, 7, 7, 7, 12, 7, 7], 2, 3))
print(solution.minDays([1000000000, 1000000000], 1, 1))
print(solution.minDays([1, 10, 2, 9, 3, 8, 4, 7, 5, 6], 4, 2))

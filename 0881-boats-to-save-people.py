from typing import List
from bisect import bisect_left


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans, left, right = 0, 0, len(people) - 1
        while (left < right):
            if people[right] > limit - people[left]:
                heavy_pos = bisect_left(people, limit - people[left] + 1, hi=right + 1)
                ans += right - heavy_pos + 1
                right = heavy_pos - 1
            if left < right:
                left += 1
                right -= 1
                ans += 1
        return ans + 1 if left == right else ans


solution = Solution()
print(solution.numRescueBoats([1, 2], 3))
print(solution.numRescueBoats([3, 2, 2, 1], 3))
print(solution.numRescueBoats([3, 5, 3, 4], 5))

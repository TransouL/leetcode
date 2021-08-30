from itertools import accumulate
from typing import List


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        diffs = [0] * (n + 1)
        for first, last, seats in bookings:
            diffs[first - 1] += seats
            diffs[last] -= seats
        return list(accumulate(diffs))[:-1]


solution = Solution()
print(solution.corpFlightBookings([[1, 2, 10], [2, 3, 20], [2, 5, 25]], 5))
print(solution.corpFlightBookings([[1, 2, 10], [2, 2, 15]], 2))

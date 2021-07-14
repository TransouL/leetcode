from typing import List


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)
        buckets = [0] * (n + 1)
        for num in arr:
            if num < n:
                buckets[num] += 1
            else:
                buckets[n] += 1

        ans = 1
        for i in range(2, n + 1):
            ans = min(ans + buckets[i], i)
        return ans

"""
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        ans = 1
        for i in range(1, len(arr)):
            ans = min(ans + 1, arr[i])
        return ans
"""


solution = Solution()
print(solution.maximumElementAfterDecrementingAndRearranging([2, 2, 1, 2, 1]))
print(solution.maximumElementAfterDecrementingAndRearranging([100, 1, 1000]))
print(solution.maximumElementAfterDecrementingAndRearranging([1, 2, 3, 4, 5]))

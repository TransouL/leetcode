from typing import List


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 1, len(arr) - 2
        while l < r:
            m = (l + r) // 2
            if arr[m] > arr[m + 1]:
                r = m
            else:
                l = m + 1
        return r


solution = Solution()
print(solution.peakIndexInMountainArray([0, 1, 0]))
print(solution.peakIndexInMountainArray([0, 2, 1, 0]))
print(solution.peakIndexInMountainArray([0, 10, 5, 2]))
print(solution.peakIndexInMountainArray([3, 4, 5, 1]))
print(solution.peakIndexInMountainArray([24, 69, 100, 99, 79, 78, 67, 36, 26, 19]))

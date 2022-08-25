from bisect import bisect_right
from typing import List


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        idx = bisect_right(arr, x)
        if idx == 0:
            return arr[:k]
        elif idx == n:
            return arr[-k:]

        left, right = idx, idx
        while k > 0 and left > 0 and arr[left - 1] == x:
            left -= 1
            k -= 1

        for i in range(k):
            if left == 0:
                right += 1
            elif right == n:
                left -= 1
            elif abs(arr[left - 1] - x) > abs(arr[right] - x):
                right += 1
            else:
                left -= 1

        return arr[left: right]


solution = Solution()
print(solution.findClosestElements(arr=[1, 2, 3, 4, 5], k=4, x=3))
print(solution.findClosestElements(arr=[1, 2, 3, 4, 5], k=4, x=-1))

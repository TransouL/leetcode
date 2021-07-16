from typing import List


class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        import bisect
        row = len(matrix)
        col = len(matrix[0])
        res = float("-inf")
        for left in range(col):
            _sum = [0] * row
            for right in range(left, col):
                for j in range(row):
                    _sum[j] += matrix[j][right]
                arr = [0]
                cur = 0
                for tmp in _sum:
                    cur += tmp
                    loc = bisect.bisect_left(arr, cur - k)
                    if loc < len(arr): res = max(cur - arr[loc], res)
                    bisect.insort(arr, cur)
        return res


solution = Solution()
print(solution.maxSumSubmatrix([[1, 0, 1], [0, -2, 3]], 2))
print(solution.maxSumSubmatrix([[2, 2, -1]], 3))

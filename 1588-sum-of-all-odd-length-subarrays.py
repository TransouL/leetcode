from typing import List


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        ans = 0
        max_step = n if n & 1 else n - 1
        for i, val in enumerate(arr):
            left_index = i + 1
            right_index = n - i
            min_index = min(left_index, right_index)
            for step in range(1, max_step + 1, 2):
                ans += val * min(min_index, n - step + 1, step)
        return ans


solution = Solution()
print(solution.sumOddLengthSubarrays([1, 4, 2, 5, 3]))
print(solution.sumOddLengthSubarrays([1, 2]))
print(solution.sumOddLengthSubarrays([10, 11, 12]))

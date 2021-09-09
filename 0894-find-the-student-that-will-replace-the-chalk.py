from typing import List


class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        n, total = len(chalk), sum(chalk)
        k = k % total
        for i, piece in enumerate(chalk):
            if k < piece:
                return i
            k -= piece


solution = Solution()
print(solution.chalkReplacer([5, 1, 5], 22))
print(solution.chalkReplacer([3, 4, 1, 2], 25))

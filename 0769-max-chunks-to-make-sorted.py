from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans, curr, max_ = 0, 0, -1
        for num in arr:
            max_ = max(max_, num)
            curr += 1
            if max_ == curr - 1:
                ans += 1
        return ans



solution = Solution()
print(solution.maxChunksToSorted([4, 3, 2, 1, 0]))
print(solution.maxChunksToSorted([1, 0, 2, 3, 4]))

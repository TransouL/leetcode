from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        ans, n = 0, len(citations)
        for i in range(n):
            if ans >= n - i:
                break
            if ans < citations[i]:
                ans = min(citations[i], n - i)
        return ans


solution = Solution()
print(solution.hIndex([3, 0, 6, 1, 5]))

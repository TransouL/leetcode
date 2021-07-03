from collections import Counter
from typing import List


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        counter = Counter(nums)
        ans = [0, 0]
        for i in range(len(nums)):
            if i + 1 not in counter:
                ans[1] = i + 1
            elif counter[i + 1] == 2:
                ans[0] = i + 1
        return ans


solution = Solution()
print(solution.findErrorNums([1, 2, 2, 4]))
print(solution.findErrorNums([1, 1]))
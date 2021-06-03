from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        ans, n, memo, counter = 0, len(nums), {0: -1}, 0
        for i in range(n):
            counter += 1 if nums[i] == 1 else -1
            if counter in memo:
                if ans < i - memo[counter]:
                    ans = i - memo[counter]
            else:
                memo[counter] = i
        return ans


solution = Solution()
print(solution.findMaxLength([0, 1]))
print(solution.findMaxLength([0, 1, 0]))

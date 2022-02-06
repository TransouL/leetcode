from typing import List


class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        stat = [0] * 101
        for num in nums:
            stat[num] += 1
        ans = 0
        for i in range(1, 101):
            if stat[i] == 1:
                ans += i
        return ans


solution = Solution()
print(solution.sumOfUnique([1, 2, 3, 2]))
print(solution.sumOfUnique([1, 1, 1, 1, 1]))
print(solution.sumOfUnique([1, 2, 3, 4, 5]))

